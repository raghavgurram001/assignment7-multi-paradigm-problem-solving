from collections import Counter
from typing import List

class StatisticsCalculator:
    """Object-oriented statistics calculator."""

    def __init__(self, data: List[int]):
        if not data:
            raise ValueError("Data list cannot be empty")
        self._data = list(data)          # defensive copy

    def mean(self) -> float:
        return sum(self._data) / len(self._data)

    def median(self) -> float:
        sorted_data = sorted(self._data)
        n = len(sorted_data)
        mid = n // 2
        if n % 2 == 1:
            return float(sorted_data[mid])
        return (sorted_data[mid - 1] + sorted_data[mid]) / 2.0

    def mode(self) -> int:
        """Return the most frequent value.
        On ties the smallest value is chosen (same behaviour as C/OCaml).
        """
        counts = Counter(self._data)
        max_freq = max(counts.values())
        # among the values that have max_freq, pick the smallest
        candidates = [val for val, freq in counts.items() if freq == max_freq]
        return min(candidates)

    def report(self) -> None:
        print("Data  :", self._data)
        print(f"Mean  : {self.mean():.2f}")
        print(f"Median: {self.median():.2f}")
        print(f"Mode  : {self.mode()}")


if __name__ == "__main__":
    sample = [14, 23, 26, 37, 45, 22, 55]
    calc = StatisticsCalculator(sample)
    calc.report()
