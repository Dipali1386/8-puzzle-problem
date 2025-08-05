# 8-Puzzle Solver (BFS & DFS)

This project demonstrates two classical uninformed search techniques — **Breadth-First Search (BFS)** and **Depth-First Search (DFS)** — to solve the 8-Puzzle problem.

The 8-Puzzle is played on a 3×3 grid containing 8 numbered tiles and one empty slot (denoted as 0). The goal is to transform the **initial state** into the **goal state** by sliding adjacent tiles into the empty position.

---

## BFS Pseudocode
while Q is not empty:
    current ← front of Q
    Dequeue Q
    if current == goal:
        return SUCCESS
    if current in visited:
        continue
    Add current to visited

    for each legal move from current:
        child ← new state after move
        if child not in visited:
            Enqueue child into Q

return FAILURE

## DFS Pseudocode
DFS(state, goal, visited, depth_limit):
    if state == goal:
        return SUCCESS
    if depth_limit == 0:
        return FAILURE

    Add state to visited

    for each legal move from state:
        child ← new state after move
        if child not in visited:
            if DFS(child, goal, visited, depth_limit - 1):
                return SUCCESS

    return FAILURE

