#프로그래머스 체육복
import sys
input = sys.stdin.readline

def solution(n, lost, reserve):
    answer = n
    real_lost = set(lost) - set(reserve)
    real_reserve = set(reserve) - set(lost)
    for i in real_lost :
        if i + 1 in real_reserve :
            real_reserve.remove(i+1)
        elif i - 1 in real_reserve :
            real_reserve.remove(i-1)
        else :
            answer -= 1
    return answer

# # case.1 return 5
# n = 5
# lost = [2,4]
# reserve = [1,3,5]

# # case.1 return 4
# n = 5
# lost = [2,4]
# reserve = [3]

# case.1 return 2
n = 3
lost = [3]
reserve = [1]

result = solution(n, lost, reserve)
print(result)