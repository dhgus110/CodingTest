/*
병합 정렬 : 분할 정복 방식을 사용해 데이터를 분할 하고 분할한 집합을 정렬하며 합치는 알고리즘

시간 복잡도 : O(nlogn)

핵심 이론 
    데이터 N개 -> 가장 작은 부분 그룹으로 setN으로 표시
    2개 씩 병합하며 정렬을 반복 

    ex) N : 8  -> set8             ( )끼리 병합하고 정렬하기 
    step1 : (set1) (set2) (set3) (set4) (set5) (set6) (set7) (set8)
    step2 : (set1, set2) = set1 (set3, set4) = set2 (set5, set6) = set3 (set7, set8) =set4
    step3 : (set1, set2) = set1 (set3, set4) = set2
    step4 : (set1, set2) = set1

2개의 그룹을 병합하는 과정 
    투 포인터 개념 이용
        그룹마다 포인터를 줘서 포인터중에서 작은 녀석을 임시 배열에 차례대로 저장


*/