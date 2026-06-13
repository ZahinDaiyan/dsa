# DSA From Scratch !!??

This repo is to implement data structures in C++ so I actually understand how they work, how memory behaves, why some operations are fast and others are slow, and how things change when you tweak implementations. and how to use them for leetcode !

I write small, commented experiments and notes as I go. No polished tutorials — just code, thoughts, and the occasional diagram I drop into the comments.

I will do stardard ds I'm using for leetcode and other helper functions here in cpp to get a better mental models of the control flow.

It is an incredible feeling when the memory layout finally clicks! You should be proud—manually managing pointers and memory safety in C++ is no joke, and you just mastered it.

## 🗺️ My Data Structures Roadmap

Now that I have solid fundamentals in Nodes, Pointers, Stacks, and Queues, I am perfectly positioned to climb higher. Here is your logical next steps roadmap:

### Phase 1: Completing the Foundations (The Linear World)

* **The Doubly Linked List (DLL):** In this session, you saw the major weakness of a Singly Linked List: you can't walk backward, making `removeLast()` an $O(N)$ operation even with a tail pointer. A Doubly Linked List gives every node a `Node* prev` pointer.
* *Why do it:* It makes `removeLast()` a true $O(1)$ operation, completing your list's superpowers.


* **The Circular Queue / Array-Based Queue:** Right now, you built a queue using nodes. Try building a Queue using a fixed-size array with "Rear" and "Front" indexes that wrap around the edges.

### Phase 2: Breaking Into Non-Linear Structures (The Hierarchical World)

Once you are comfortable linking nodes in a straight line, it's time to let nodes link to *multiple* other nodes.

* **Binary Search Trees (BST):** Instead of a node pointing to just `next`, a tree node points to a `left` child and a `right` child.
* *Why do it:* This introduces you to **Recursion** and allows you to search, insert, and delete data in lightning-fast $O(\log N)$ time.


* **Heaps (Priority Queues):** A special type of tree usually implemented inside an array. It allows you to build a queue where elements aren't served strictly by arrival time, but by "importance" (like an ER room treating the most critical patient first).

### Phase 3: The Ultimate Network (Graphs)

* **Graphs:** Nodes can connect to any other nodes in a massive web (like a social network of friends, or cities connected by highways). You'll learn how algorithms find the shortest path between two points (the literal math behind Google Maps).
