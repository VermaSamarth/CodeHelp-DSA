def solve(a, b, c):
    nums = [a, b, c]
    nums.sort()
    a, b, c = nums[0], nums[1], nums[2]
    
    # We have 5 increments to use
    increments = 5
    
    # Distribute the increments optimally
    while increments > 0:
        if a <= b and a <= c:
            a += 1
        elif b <= a and b <= c:
            b += 1
        else:
            c += 1
        increments -= 1
    
    # Return the maximum product after all increments
    return a * b * c

def main():
    t = int(input().strip())
    for _ in range(t):
        a, b, c = map(int, input().strip().split())
        print(solve(a, b, c))

if __name__ == "__main__":
    main()
