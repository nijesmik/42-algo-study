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
   ❌ 브랜치에서 절대 `git pull` 명령어 사용 금지 ❌

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
|| 23.12.27 (수) | [톱니바퀴](https://www.acmicpc.net/problem/14891) | <img src="https://static.solved.ac/tier_small/11.svg" height="25" align="center"/> | 시뮬레이션 |
|| 24.12.29 (금) | [늑대와 양](https://www.acmicpc.net/problem/16956) | <img src="https://static.solved.ac/tier_small/8.svg" height="25" align="center"/> | - |


<!-- problem table template

| 24.00.00 (❓) | [❓](https://www.acmicpc.net/problem/❓) | <img src="https://static.solved.ac/tier_small/❓.svg" height="25" align="center"/> | BFS |

 -->
