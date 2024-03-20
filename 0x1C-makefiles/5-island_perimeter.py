#!/usr/bin/python3
"""Island Perimeter Module that returns the perimeter of the island"""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in grid.
    Args:
    grid (list of list of int): Grid rep.
    Returns:
    int: Island perimeter.
    """
    prmter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                prmter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    prmter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    prmter -= 2

    return prmter
