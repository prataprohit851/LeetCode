from queue import PriorityQueue


class SeatManager:

    def __init__(self, n: int):
        self.q = PriorityQueue()
        for i in range(1, n+1):
            self.q.put(i)

    def reserve(self) -> int:
        item = self.q.get()
        return item

    def unreserve(self, seatNumber: int) -> None:
        self.q.put(seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)