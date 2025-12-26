(() => {
  const canvas = document.getElementById("game");
  const ctx = canvas.getContext("2d");

  // Scoreboard elements
  const scoreLeftEl = document.getElementById("score-left");
  const scoreRightEl = document.getElementById("score-right");

  // Game config
  const CW = canvas.width;
  const CH = canvas.height;

  const PADDLE_WIDTH = 12;
  const PADDLE_HEIGHT = 100;
  const PADDLE_SPEED = 7;
  const AI_SPEED = 5.5; // Computer paddle max speed per frame

  const BALL_RADIUS = 8;
  const BALL_START_SPEED = 5;
  const BALL_SPEED_INCREMENT = 1.03; // speed up after paddle hits
  const BALL_MAX_SPEED = 11;
  const MAX_BOUNCE_ANGLE = (60 * Math.PI) / 180; // 60 degrees

  const NET_SEGMENT = 12;
  const NET_GAP = 12;

  // State
  const left = {
    x: 16,
    y: CH / 2 - PADDLE_HEIGHT / 2,
    w: PADDLE_WIDTH,
    h: PADDLE_HEIGHT,
    dy: 0,
  };

  const right = {
    x: CW - 16 - PADDLE_WIDTH,
    y: CH / 2 - PADDLE_HEIGHT / 2,
    w: PADDLE_WIDTH,
    h: PADDLE_HEIGHT,
  };

  const ball = {
    x: CW / 2,
    y: CH / 2,
    r: BALL_RADIUS,
    vx: 0,
    vy: 0,
    speed: BALL_START_SPEED,
    active: true, // false during serve delay/pause
  };

  const score = { left: 0, right: 0 };

  let paused = false;
  let lastTime = 0;

  // Utility
  function clamp(v, min, max) {
    return Math.max(min, Math.min(max, v));
  }

  function serve(towardsRight = Math.random() < 0.5) {
    ball.x = CW / 2;
    ball.y = CH / 2;
    // random angle within ±30° to avoid too flat start
    const angle = (Math.random() * (Math.PI / 3) - Math.PI / 6);
    ball.speed = BALL_START_SPEED;
    ball.vx = (towardsRight ? 1 : -1) * ball.speed * Math.cos(angle);
    ball.vy = ball.speed * Math.sin(angle);
    ball.active = false;
    // Short delay before activating
    setTimeout(() => {
      ball.active = !paused;
    }, 600);
  }

  function resetAfterScore(scoredRight) {
    // If right scored (ball exited left), serve towards left (player) so they receive
    serve(!scoredRight);
  }

  // Input: keyboard
  const keys = new Set();
  window.addEventListener("keydown", (e) => {
    if (e.code === "ArrowUp" || e.code === "ArrowDown") {
      e.preventDefault();
    }
    if (e.code === "Space") {
      togglePause();
      return;
    }
    keys.add(e.code);
    updatePaddleVelocityFromKeys();
  });

  window.addEventListener("keyup", (e) => {
    keys.delete(e.code);
    updatePaddleVelocityFromKeys();
  });

  function updatePaddleVelocityFromKeys() {
    const up = keys.has("ArrowUp");
    const down = keys.has("ArrowDown");
    if (up && !down) left.dy = -PADDLE_SPEED;
    else if (down && !up) left.dy = PADDLE_SPEED;
    else left.dy = 0;
  }

  // Input: mouse controls left paddle by vertical position over canvas
  canvas.addEventListener("mousemove", (e) => {
    const rect = canvas.getBoundingClientRect();
    const mouseY = e.clientY - rect.top;
    left.y = clamp(mouseY - left.h / 2, 0, CH - left.h);
  });

  // Click to pause/resume
  canvas.addEventListener("click", togglePause);
  function togglePause() {
    paused = !paused;
    if (!paused) {
      // If unpausing and ball was inactive, reactivate after a tiny moment to give user context
      if (!ball.active) {
        setTimeout(() => (ball.active = true), 100);
      } else {
        // Resume normal loop
        // no-op; loop continues
      }
    } else {
      // Pausing: freeze ball without changing velocity values
      ball.active = false;
    }
  }

  // Resize handling (optional: keep canvas pixels fixed, CSS scales it)
  // If you want to handle high-DPI crispness, you could scale canvas by devicePixelRatio.
  // This version keeps it simple.

  function update(dt) {
    // Player paddle (keyboard motion)
    left.y = clamp(left.y + left.dy, 0, CH - left.h);

    // AI paddle movement: track ball with capped speed
    const aiTargetY = ball.y - right.h / 2;
    const diff = aiTargetY - right.y;
    const step = clamp(diff, -AI_SPEED, AI_SPEED);
    // Only chase aggressively if ball moving towards AI, else ease back to center
    if (ball.vx > 0 && ball.active) {
      right.y += step;
    } else {
      const centerTarget = CH / 2 - right.h / 2;
      const backDiff = centerTarget - right.y;
      right.y += clamp(backDiff, -AI_SPEED * 0.7, AI_SPEED * 0.7);
    }
    right.y = clamp(right.y, 0, CH - right.h);

    // Ball physics
    if (ball.active) {
      ball.x += ball.vx;
      ball.y += ball.vy;
    }

    // Wall collisions (top/bottom)
    if (ball.y - ball.r <= 0) {
      ball.y = ball.r;
      ball.vy *= -1;
    } else if (ball.y + ball.r >= CH) {
      ball.y = CH - ball.r;
      ball.vy *= -1;
    }

    // Paddle collisions
    // Left paddle
    if (
      ball.vx < 0 &&
      ball.x - ball.r <= left.x + left.w &&
      ball.y >= left.y &&
      ball.y <= left.y + left.h
    ) {
      ball.x = left.x + left.w + ball.r; // avoid sinking
      const relativeIntersectY = ball.y - (left.y + left.h / 2);
      const normalized = relativeIntersectY / (left.h / 2);
      const bounceAngle = normalized * MAX_BOUNCE_ANGLE;

      ball.speed = Math.min(BALL_MAX_SPEED, ball.speed * BALL_SPEED_INCREMENT);
      ball.vx = ball.speed * Math.cos(bounceAngle);
      ball.vy = ball.speed * Math.sin(bounceAngle);
    }

    // Right paddle
    if (
      ball.vx > 0 &&
      ball.x + ball.r >= right.x &&
      ball.y >= right.y &&
      ball.y <= right.y + right.h
    ) {
      ball.x = right.x - ball.r; // avoid sinking
      const relativeIntersectY = ball.y - (right.y + right.h / 2);
      const normalized = relativeIntersectY / (right.h / 2);
      const bounceAngle = normalized * MAX_BOUNCE_ANGLE;

      ball.speed = Math.min(BALL_MAX_SPEED, ball.speed * BALL_SPEED_INCREMENT);
      ball.vx = -ball.speed * Math.cos(bounceAngle);
      ball.vy = ball.speed * Math.sin(bounceAngle);
    }

    // Scoring
    if (ball.x + ball.r < 0) {
      // Computer scores
      score.right += 1;
      updateScoreboard();
      resetAfterScore(true); // right scored
    } else if (ball.x - ball.r > CW) {
      // Player scores
      score.left += 1;
      updateScoreboard();
      resetAfterScore(false); // left scored
    }
  }

  function updateScoreboard() {
    scoreLeftEl.textContent = String(score.left);
    scoreRightEl.textContent = String(score.right);
  }

  function draw() {
    // Background
    ctx.fillStyle = "#000";
    ctx.fillRect(0, 0, CW, CH);

    // Center net
    ctx.strokeStyle = "rgba(255,255,255,0.25)";
    ctx.lineWidth = 2;
    for (let y = 0; y < CH; y += NET_SEGMENT + NET_GAP) {
      ctx.beginPath();
      ctx.moveTo(CW / 2, y);
      ctx.lineTo(CW / 2, y + NET_SEGMENT);
      ctx.stroke();
    }

    // Paddles
    ctx.fillStyle = "#FFFFFF";
    ctx.fillRect(left.x, left.y, left.w, left.h);
    ctx.fillRect(right.x, right.y, right.w, right.h);

    // Ball
    ctx.beginPath();
    ctx.arc(ball.x, ball.y, ball.r, 0, Math.PI * 2);
    ctx.fill();

    // On pause or serve delay, show overlay
    if (!ball.active) {
      ctx.fillStyle = "rgba(0,0,0,0.4)";
      ctx.fillRect(0, 0, CW, CH);

      ctx.fillStyle = "#FFFFFF";
      ctx.font = "bold 22px system-ui, -apple-system, Segoe UI, Roboto, Helvetica, Arial";
      ctx.textAlign = "center";
      ctx.fillText(paused ? "Paused" : "Get Ready...", CW / 2, CH / 2);
      ctx.font = "14px system-ui, -apple-system, Segoe UI, Roboto, Helvetica, Arial";
      ctx.fillText("Click to pause/resume • Move mouse or use Arrow Up/Down", CW / 2, CH / 2 + 26);
    }
  }

  function loop(timestamp) {
    const dt = Math.min(32, timestamp - lastTime); // ms cap for stability
    lastTime = timestamp;

    if (!paused) {
      update(dt);
    }
    draw();
    requestAnimationFrame(loop);
  }

  // Initialize
  updateScoreboard();
  serve(Math.random() < 0.5); // random initial serve direction
  requestAnimationFrame((t) => {
    lastTime = t;
    requestAnimationFrame(loop);
  });

  // Accessibility: allow focusing the canvas
  canvas.tabIndex = 0;
})();