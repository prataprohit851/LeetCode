class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        d = defaultdict(list)
        for pair in adjacentPairs:
            for num in pair:
                d[num].append(pair)
        l1 = []
        for key, value in d.items():
            if len(value) == 1:
                l1.append(key)
                break
        visited = set()
        visited.add(l1[0])
        while len(l1) < len(adjacentPairs)+1:
            for pair in d[l1[-1]]:
                if pair[0] not in visited:
                    visited.add(pair[0])
                    l1.append(pair[0])
                elif pair[1] not in visited:
                    visited.add(pair[1])
                    l1.append(pair[1])
        return l1


# from collections import defaultdict
# from typing import List

# class Solution:
#     def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
#         # Create a defaultdict to store pairs based on their elements
#         d = defaultdict(list)
        
#         # Populate the defaultdict with pairs
#         for pair in adjacentPairs:
#             for num in pair:
#                 d[num].append(pair)

#         # Initialize the list to store the reconstructed array
#         l1 = []
        
#         # Use a set to keep track of visited elements
#         visited = set()
        
#         # Find the starting element for the reconstructed array
#         for key, value in d.items():
#             if len(value) == 1:
#                 l1.append(key)
#                 break
        
#         # Add the first element to the visited set
#         visited.add(l1[0])

#         # Reconstruct the array until it's complete
#         while len(l1) < len(adjacentPairs) + 1:
#             last_num = l1[-1]  # Get the last number added to the array
#             for pair in d[last_num]:  # Iterate through pairs related to the last number
#                 if pair[0] not in visited:  # Check if the first element of the pair is not visited
#                     l1.append(pair[0])  # Add it to the array
#                     visited.add(pair[0])  # Add it to the visited set
#                 elif pair[1] not in visited:  # If the first element is visited, check the second element
#                     l1.append(pair[1])  # Add the second element to the array
#                     visited.add(pair[1])  # Add it to the visited set

#         return l1  # Return the reconstructed array