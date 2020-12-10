class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        maxRow = [min(row) for row in matrix]
        maxCol = [max(col) for col in zip(*matrix)]
        return set(maxRow).intersection(maxCol)
