import time
import random
import numpy as np
import matplotlib.pyplot as plt

def sequential_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def ternary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid1 = left + (right - left) // 3
        mid2 = right - (right - left) // 3
        if arr[mid1] == target:
            return mid1
        if arr[mid2] == target:
            return mid2
        if target < arr[mid1]:
            right = mid1 - 1
        elif target > arr[mid2]:
            left = mid2 + 1
        else:
            left, right = mid1 + 1, mid2 - 1
    return -1

def interpolation_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right and arr[left] <= target <= arr[right]:
        pos = left + ((target - arr[left]) * (right - left)) // (arr[right] - arr[left])
        if arr[pos] == target:
            return pos
        if arr[pos] < target:
            left = pos + 1
        else:
            right = pos - 1
    return -1

def fibonacci_search(arr, target):
    fib2, fib1 = 0, 1
    fib = fib2 + fib1
    while fib < len(arr):
        fib2, fib1 = fib1, fib
        fib = fib2 + fib1
    index = -1
    while fib > 1:
        i = min(index + fib2, len(arr) - 1)
        if arr[i] < target:
            fib, fib1, fib2 = fib1, fib2, fib1 - fib2
            index = i
        elif arr[i] > target:
            fib, fib1, fib2 = fib2, fib1 - fib2, fib2 - fib1
        else:
            return i
    if fib1 and index + 1 < len(arr) and arr[index + 1] == target:
        return index + 1
    return -1

sizes = [100, 1000, 5000, 10000, 50000, 100000]
time_results = {"Sequential": [], "Binary": [], "Ternary": [], "Interpolation": [], "Fibonacci": []}

for n in sizes:
    arr = sorted(random.sample(range(n * 10), n))
    target = random.choice(arr)
    
    for name, search_func in zip(time_results.keys(), [sequential_search, binary_search, ternary_search, interpolation_search, fibonacci_search]):
        start = time.time()
        search_func(arr, target)
        end = time.time()
        time_results[name].append(end - start)

plt.figure(figsize=(10, 6))
for name, times in time_results.items():
    plt.plot(sizes, times, marker='o', label=name)
plt.xlabel('Input Size (n)')
plt.ylabel('Time (seconds)')
plt.title('Comparison of Search Algorithms')
plt.legend()
plt.grid()
plt.show()
