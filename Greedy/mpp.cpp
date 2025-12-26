// Bilkul Gurudas 👌
// Chalo ab tak jo humne **hash table / map / unordered_map** ke concepts padhe, unka ek **concise but complete summary** bana dete hain. Ye ekdum quick reference jaise hai, jo exam ya interview ke liye perfect hai.

// ---

// ## **C++ Map / Unordered_map Summary**

// ### **1. Map vs Unordered_map**

// | Feature         | `map`                         | `unordered_map`             |
// | --------------- | ----------------------------- | --------------------------- |
// | Data Structure  | Red-Black Tree (Balanced BST) | Hash Table                  |
// | Key Order       | Sorted (ascending)            | Random / Unordered          |
// | Time Complexity | O(log n) insert/find/erase    | Average O(1), Worst O(n)    |
// | Keys            | Unique                        | Unique                      |
// | STL Function    | `map<int,int> m;`             | `unordered_map<int,int> m;` |

// ---

// ### **2. Basic Operations**

// ```cpp
// map<string,int> m;
// m["apple"] = 50;          // Insert/update
// m.at("apple");             // Access (throws error if not exist)
// m.find("apple");           // Returns iterator
// m.erase("apple");          // Delete key
// m.size();                  // Number of elements
// m.empty();                 // Check empty
// m.clear();                 // Remove all elements
// ```

// * `map["key"]` → agar key nahi exist → **default value insert** hoti hai
// * `m.find(key)` → agar key exist nahi → **m.end()** return

// ---

// ### **3. Hash Table Basics (`unordered_map`)**

// 1. **Hash Function** → Key ko numeric **hash code** me convert karta hai
// 2. **Compression Function** → Hash code ko **bucket index** me fit karta hai

//    ```cpp
//    index = hashCode % bucket_count;
//    ```
// 3. **Collision** → Jab 2 keys same bucket me aa jaye
// 4. **Collision Resolution**

//    * **Open Hashing / Separate Chaining** → Linked list / vector me store
//    * **Closed Addressing / Open Addressing** → Table ke andar probing (linear/quadratic/double hashing)

// ---

// ### **4. Load Factor (α)**

// [
// \alpha = \frac{n}{b} \quad (n = elements, b = buckets)
// ]

// * Threshold ≈ 0.7–0.75
// * Agar α > threshold → **Rehashing** (table resize & all elements reinserted)

// ---

// ### **5. Buckets**

// * **Bucket = slot in hash table**
// * **Bucket count** = total slots
// * Default (implementation dependent) → usually power of 2 or nearest prime
// * Manually set possible:

// ```cpp
// unordered_map<int,int> m(50);  // Compiler picks nearest prime >=50
// ```

// ---

// ### **6. Key Points / Tips**

// 1. `map` → automatically **sorted order**, O(log n) operations
// 2. `unordered_map` → **average O(1)** insertion/search
// 3. Open Hashing → collisions **linked list me store**
// 4. Closed Addressing → collisions **probing**
// 5. Linear Probing → **primary clustering problem**
// 6. `map[key] = value` → insert/update key efficiently
// 7. `find(key)` → check existence
// 8. Load factor control → rehashing for performance

// ---

// ### ✅ **Visual Concept Flow**

// ```
// Key → Hash Function → Hash Code → Compression Function → Bucket Index
// → Store key-value
// → Collision? → Chaining / Probing
// → Check Load Factor → Rehash if > 0.7
// ```

// ---

// Agar tu chaho, mai is summary ka **diagram + hash table flow chart** bhi bana du, jisme **bucket array, hash code, collision, chaining/probing, rehashing** visually dikh jaye —
// Ye dekh kar sab concepts **instant yaad** ho jayenge.

// Kya mai wo bana du?
