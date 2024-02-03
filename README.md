# 42Seoul Algorithm Study

## 🙋 참여 방법

1. repository fork
2. 브랜치 생성

   ```sh
   git checkout -b <branch_name>
   ```

   > ❓ Q&A <br>
   > Q1: fork 했는데 그냥 브랜치 안 만들고 해도 되나요? <br>
   > A1: **안됩니다.**
   >
   > Q2: 브랜치 왜 만드는데요? <br>
   > A2: **충돌 방지**와 **본인 파일만 따로 관리**하기 위해 만듭니다.

   ⚠️ **주의사항** <br>
   ❌ 브랜치에서 절대 `sync fork` 및 `git pull` 금지 ❌

3. 만든 브랜치를 remote repository에 등록

   ```sh
   git push -u origin <branch_name>
   ```

4. 푼 문제를 1️⃣ **본인의 `intra id` 폴더에 넣고**, 2️⃣ **[convention](#commit)에 맞춰** commit

5. 제출 기한까지 본인의 브랜치를 **[convention](#pr)에 맞춰** PR

   📅 제출 기한 : 매주 화/금 23시 59분 59초 <br>
   💸 벌금 : 3000원 + 1000원 * 누적 미제출 횟수

## 🤝 Convention

### commit

```
<tag>: <problem_name>
```

1. 문제별로 각각 commit

2. tag는 소문자로 작성

   | tag      | 설명                                |
   | -------- | ---------------------------------- |
   | feat     | 문제 제출                            |
   | fix      | 틀린 문제 수정                        |
   | refactor | 맞은 문제 리팩토링                     |
   | style    | formatting, missing semi colons 등 |
   | docs     | documentation                      |
   | chore    | move or rename resources, maintain |
   | merge    | merge                              |

### PR

```
[<week>] <intra_id>
```

1. PR 제목은 모두 소문자로 작성

2. 해당하는 요일의 라벨을 함께 달아주세요!

## ✍️ 문제

| 분류 | 제출일 | 문제 | 난이도 | 주제 |
| :-: | :--: | :-: | :--: | :-: |
| week01 | 23.12.26 (화) | [날짜 계산](https://www.acmicpc.net/problem/1476) | <img src="https://static.solved.ac/tier_small/6.svg" height="25" align="center"/> | 브루트 포스 |
|| 23.12.27 (수) | [톱니바퀴](https://www.acmicpc.net/problem/14891) | <img src="https://static.solved.ac/tier_small/11.svg" height="25" align="center"/> | [시뮬레이션](https://www.acmicpc.net/workbook/view/7316) |
|| 23.12.29 (금) | [늑대와 양](https://www.acmicpc.net/problem/16956) | <img src="https://static.solved.ac/tier_small/8.svg" height="25" align="center"/> | [BFS](https://www.acmicpc.net/workbook/view/3990) |
|| 23.12.30 (토) | [치킨 배달](https://www.acmicpc.net/problem/15686) | <img src="https://static.solved.ac/tier_small/11.svg" height="25" align="center"/> | [시뮬레이션](https://www.acmicpc.net/workbook/view/7316) |
| week02 | 24.01.02 (화) | [다음 순열](https://www.acmicpc.net/problem/10972) | <img src="https://static.solved.ac/tier_small/8.svg" height="25" align="center"/> | [순열](https://www.acmicpc.net/workbook/view/3964) |
|| 24.01.03 (수) | [컨베이어 벨트 위의 로봇](https://www.acmicpc.net/problem/20055) | <img src="https://static.solved.ac/tier_small/11.svg" height="25" align="center"/> | [시뮬레이션](https://www.acmicpc.net/workbook/view/7316) |
|| 24.01.05 (금) | [수들의 합 2](https://www.acmicpc.net/problem/2003) | <img src="https://static.solved.ac/tier_small/7.svg" height="25" align="center"/> | 투 포인터 |
|| 24.01.06 (토) | [파이프 옮기기 1](https://www.acmicpc.net/problem/17070) | <img src="https://static.solved.ac/tier_small/11.svg" height="25" align="center"/> | [시뮬레이션](https://www.acmicpc.net/workbook/view/7316) |
| week03 | 24.01.09 (화) | [최단경로](https://www.acmicpc.net/problem/1753) | <img src="https://static.solved.ac/tier_small/12.svg" height="25" align="center"/> | 다익스트라 알고리즘 |
|| 24.01.10 (수) | [상어 초등학교](https://www.acmicpc.net/problem/21608) | <img src="https://static.solved.ac/tier_small/11.svg" height="25" align="center"/> | [시뮬레이션](https://www.acmicpc.net/workbook/view/7316) |
|| 24.01.12 (금) | [퇴사](https://www.acmicpc.net/problem/14501) | <img src="https://static.solved.ac/tier_small/8.svg" height="25" align="center"/> | [다이나믹 프로그래밍](https://www.acmicpc.net/workbook/view/7319) |
|| 24.01.13 (토) | [배열 복원하기](https://www.acmicpc.net/problem/16967) | <img src="https://static.solved.ac/tier_small/8.svg" height="25" align="center"/> | [시뮬레이션과 구현](https://www.acmicpc.net/workbook/view/9380) |
| week04 | 24.01.16 (화) | [수 찾기](https://www.acmicpc.net/problem/1920) | <img src="https://static.solved.ac/tier_small/7.svg" height="25" align="center"/> | [이분탐색](https://www.acmicpc.net/workbook/view/8400) |
|| 24.01.17 (수) | [LCD Test](https://www.acmicpc.net/problem/2290) | <img src="https://static.solved.ac/tier_small/9.svg" height="25" align="center"/> | [시뮬레이션과 구현](https://www.acmicpc.net/workbook/view/9380) |
|| 24.01.19 (금) | [그림](https://www.acmicpc.net/problem/1926) | <img src="https://static.solved.ac/tier_small/10.svg" height="25" align="center"/> | [BFS](https://www.acmicpc.net/workbook/view/7313) |
|| 24.01.20 (토) | [상범 빌딩](https://www.acmicpc.net/problem/6593) | <img src="https://static.solved.ac/tier_small/11.svg" height="25" align="center"/> | [BFS](https://www.acmicpc.net/workbook/view/7313) |
| week05 | 24.01.23 (화) | [강의실 배정](https://www.acmicpc.net/problem/11000) | <img src="https://static.solved.ac/tier_small/11.svg" height="25" align="center"/> | [그리디](https://www.acmicpc.net/workbook/view/7320) |
|| 24.01.24 (수) | [레벨 햄버거](https://www.acmicpc.net/problem/16974) | <img src="https://static.solved.ac/tier_small/11.svg" height="25" align="center"/> | [시뮬레이션과 구현](https://www.acmicpc.net/workbook/view/9389) |
|| 24.01.26 (금) | [용액 합성하기](https://www.acmicpc.net/problem/14921) | <img src="https://static.solved.ac/tier_small/11.svg" height="25" align="center"/> | [이분탐색](https://www.acmicpc.net/workbook/view/8400) |
|| 24.01.27 (토) | [톱니바퀴 (2)](https://www.acmicpc.net/problem/15662) | <img src="https://static.solved.ac/tier_small/11.svg" height="25" align="center"/> | [시뮬레이션과 구현](https://www.acmicpc.net/workbook/view/9380) |
| week06 | 24.01.30 (화) | [랜선 자르기](https://www.acmicpc.net/problem/1654) | <img src="https://static.solved.ac/tier_small/9.svg" height="25" align="center"/> | [이분 탐색](https://www.acmicpc.net/workbook/view/3984) |
|| 24.01.31 (수) | [배열 돌리기 2](https://www.acmicpc.net/problem/16927) | <img src="https://static.solved.ac/tier_small/11.svg" height="25" align="center"/> | [시뮬레이션과 구현](https://www.acmicpc.net/workbook/view/9380) |
|| 24.02.02 (금) | [수 이어 쓰기 2](https://www.acmicpc.net/problem/1790) | <img src="https://static.solved.ac/tier_small/11.svg" height="25" align="center"/> | [이분 탐색](https://www.acmicpc.net/workbook/view/3984) |
|| 24.02.03 (토) | [미세먼지 안녕!](https://www.acmicpc.net/problem/17144) | <img src="https://static.solved.ac/tier_small/12.svg" height="25" align="center"/> | [시뮬레이션과 구현](https://arc.net/l/quote/wigwwfes) |
| week07 | 24.02.07 (수) | [로프](https://www.acmicpc.net/problem/2217) | <img src="https://static.solved.ac/tier_small/7.svg" height="25" align="center"/> | [그리디](https://www.acmicpc.net/workbook/view/7320) |
||| [주사위 굴리기](https://www.acmicpc.net/problem/14499) | <img src="https://static.solved.ac/tier_small/12.svg" height="25" align="center"/> | [시뮬레이션](https://www.acmicpc.net/workbook/view/7316) |
|| 24.02.10 (토) | [수 묶기](https://www.acmicpc.net/problem/1744) | <img src="https://static.solved.ac/tier_small/12.svg" height="25" align="center"/> | [그리디](https://www.acmicpc.net/workbook/view/7320) |
||| [배열 돌리기 3](https://www.acmicpc.net/problem/16935) | <img src="https://static.solved.ac/tier_small/11.svg" height="25" align="center"/> | [시뮬레이션과 구현](https://www.acmicpc.net/workbook/view/9380) |
|| Bonus | [도넛과 막대 그래프](https://school.programmers.co.kr/learn/courses/30/lessons/258711) | Lv.2 | Programmers |

<!-- problem table template

| week0❓ | 24.00.00 (화) | [❓](https://www.acmicpc.net/problem/❓) | <img src="https://static.solved.ac/tier_small/❓.svg" height="25" align="center"/> | - |
|| 24.00.00 (수) | [❓](https://www.acmicpc.net/problem/❓) | <img src="https://static.solved.ac/tier_small/❓.svg" height="25" align="center"/> | - |
|| 24.00.00 (금) | [❓](https://www.acmicpc.net/problem/❓) | <img src="https://static.solved.ac/tier_small/❓.svg" height="25" align="center"/> | - |
|| 24.00.00 (토) | [❓](https://www.acmicpc.net/problem/❓) | <img src="https://static.solved.ac/tier_small/❓.svg" height="25" align="center"/> | - |

 -->
