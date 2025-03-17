import matplotlib.pyplot as plt
import time
import numpy as np

# 1. Các thuật toán tìm kiếm

# Thuật toán tìm kiếm tuyến tính
def linear_search(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1

# Thuật toán tìm kiếm nhị phân
def binary_search(arr, x):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            left = mid + 1
        else:
            right = mid - 1
    return -1

# Thuật toán tìm kiếm tam phân
def ternary_search(arr, left, right, x):
    if left > right:
        return -1
    mid1 = left + (right - left) // 3
    mid2 = right - (right - left) // 3
    if arr[mid1] == x:
        return mid1
    if arr[mid2] == x:
        return mid2
    if x < arr[mid1]:
        return ternary_search(arr, left, mid1 - 1, x)
    elif x > arr[mid2]:
        return ternary_search(arr, mid2 + 1, right, x)
    else:
        return ternary_search(arr, mid1 + 1, mid2 - 1, x)

# Thuật toán tìm kiếm nội suy
def interpolation_search(arr, x):
    low, high = 0, len(arr) - 1
    while low <= high and x >= arr[low] and x <= arr[high]:
        if low == high:
            if arr[low] == x:
                return low
            return -1
        pos = low + ((high - low) // (arr[high] - arr[low]) * (x - arr[low]))
        if arr[pos] == x:
            return pos
        elif arr[pos] < x:
            low = pos + 1
        else:
            high = pos - 1
    return -1

# Thuật toán tìm kiếm Fibonacci
def fibonacci_search(arr, x):
    fibMMm2 = 0  # (m-2)'th Fibonacci number
    fibMMm1 = 1  # (m-1)'th Fibonacci number
    fibM = fibMMm2 + fibMMm1  # m'th Fibonacci number
    n = len(arr)

    # Tìm số Fibonacci lớn nhất nhỏ hơn hoặc bằng n
    while fibM < n:
        fibMMm2 = fibMMm1
        fibMMm1 = fibM
        fibM = fibMMm2 + fibMMm1

    offset = -1

    while fibM > 1:
        i = min(offset + fibMMm2, n - 1)
        if arr[i] < x:
            fibM = fibMMm1
            fibMMm1 = fibMMm2
            fibMMm2 = fibM - fibMMm1
            offset = i
        elif arr[i] > x:
            fibM = fibMMm2
            fibMMm1 = fibMMm1 - fibMMm2
            fibMMm2 = fibM - fibMMm1
        else:
            return i
    if fibMMm1 and offset + 1 < n and arr[offset + 1] == x:
        return offset + 1
    return -1

# 2. Hàm đo thời gian thực thi
def measure_time(algorithm, arr, x):
    start = time.time()
    algorithm(arr, x)
    end = time.time()
    return (end - start) * 1000  # Thời gian tính bằng ms

# 3. Khảo sát
n_values = [100, 500, 1000, 5000, 10000, 20000]  # Các giá trị n
linear_times = []
binary_times = []
ternary_times = []
interpolation_times = []
fibonacci_times = []

for n in n_values:
    arr = np.arange(n)  # Tạo mảng đã sắp xếp
    x = -1  # Phần tử không tồn tại trong mảng

    linear_times.append(measure_time(linear_search, arr, x))
    binary_times.append(measure_time(binary_search, arr, x))
    ternary_times.append(measure_time(lambda arr, x: ternary_search(arr, 0, len(arr) - 1, x), arr, x))
    interpolation_times.append(measure_time(interpolation_search, arr, x))
    fibonacci_times.append(measure_time(fibonacci_search, arr, x))

# 4. Vẽ đồ thị
plt.figure(figsize=(12, 8))
plt.plot(n_values, linear_times, marker='o', label='Tuyến tính (O(n))')
plt.plot(n_values, binary_times, marker='o', label='Nhị phân (O(log n))')
plt.plot(n_values, ternary_times, marker='o', label='Tam phân (O(log n))')
plt.plot(n_values, interpolation_times, marker='o', label='Nội suy (O(log log n))')
plt.plot(n_values, fibonacci_times, marker='o', label='Fibonacci (O(log n))')

plt.title('Thời gian thực thi các thuật toán tìm kiếm')
plt.xlabel('Kích thước mảng (n)')
plt.ylabel('Thời gian thực thi (ms)')
plt.legend()
plt.grid(True)
plt.show()
