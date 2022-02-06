#프로그래머스 체육복
#ver.2 지난번 틀렸던것 수정
import sys
input = sys.stdin.readline

def solution(n, lost, reserve):
    tmp_lost = []
    real_reserve = set(reserve) - set(lost) # 여벌을 가져오고 도난당하지 않은 학생
    real_lost = set(lost) - set(reserve) # 여벌을 가져오자 못하고 도난당한 학생
    for i in real_lost :
        if i-1 in real_reserve :
            real_reserve.remove(i-1)
            tmp_lost.append(i)
        elif i+1 in real_reserve :
            real_reserve.remove(i+1)
            tmp_lost.append(i)
    real_lost = len(real_lost) - len(set(tmp_lost))
    answer = n - real_lost
    return answer

# case.1 return 5
n = 5
lost = [2,4]
reserve = [1,3,5]

# # case.2 return 5
# n = 5
# lost = [3,4]
# reserve = [1,3,5]

# # case.3 return 4
# n = 5
# lost = [2,4]
# reserve = [3]
result = solution(n, lost, reserve)
print(result)