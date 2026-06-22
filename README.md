# Algorithm.c

C 언어로 구현한 **정렬 알고리즘 성능 비교** 벤치마크 프로그램입니다.  
동일한 난수 배열에 8가지 정렬 알고리즘을 적용하고 실행 시간(ms)을 출력합니다.

## 구현 알고리즘

| 알고리즘 | 함수명 | 설명 |
|----------|--------|------|
| 버블 정렬 | `bubble` | 인접 원소 교환, 조기 종료 최적화 |
| 선택 정렬 | `selection` | 최솟값을 앞으로 |
| 삽입 정렬 | `insertion` | 정렬된 구간에 삽입 |
| 셸 정렬 | `shell` | 간격을 줄여가며 삽입 정렬 |
| 퀵 정렬 | `quick` | 분할 정복 |
| 병합 정렬 | `mergesort` | 분할 후 병합 |
| 힙 정렬 | `heapsort` | 힙 자료구조 활용 |
| 계수 정렬 | `counting` | 값 범위 기반 (0~999) |

## 벤치마크 설정

- **데이터 크기**: 10,000 / 20,000 / 30,000 / 40,000 / 50,000
- **값 범위**: 0 ~ 999 (난수)
- **측정**: `clock()` 기반 밀리초(ms)

## 실행 방법

### Windows (MinGW / MSVC)

```bash
gcc QuickTest.c -o QuickTest.exe
QuickTest.exe
```

### Linux / macOS

```bash
gcc QuickTest.c -o QuickTest
./QuickTest
```

## 출력 예시

```
Bubble, 10000: 1234.56ms
Selection, 10000: 567.89ms
Insertion, 10000: 345.67ms
...
Quick, 10000: 12.34ms
Merge, 10000: 15.67ms
Heap, 10000: 18.90ms
Counting, 10000: 2.34ms
```

## 프로젝트 구조

```
Algorithm.c/
└── QuickTest.c    # 정렬 구현 + main 벤치마크
```

## 학습 포인트

- O(n²) vs O(n log n) vs O(n) 알고리즘의 실측 차이 확인
- 동일 입력에 대한 알고리즘별 성능 비교
- C 언어 포인터·메모리 할당(`malloc`, `calloc`, `free`) 활용
