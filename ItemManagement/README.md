* ItemList라는 txt파일로 부터 Item의 이름 / 가격 / 개수 순서대로 입력 되어있는 것을 가정함*

1. Load -  ItemList의 물건 목록들을 불러와서 데이터를 저장함
2. Insert는 콘솔창에서 아이템을 입력하여 데이터를 저장함
3. update는 기존 정보 update 함
4. delete는 아이템 정보 삭제
5. Print는 아이템 정보 출력
6. Save는 콘솔창에 Insert로 입력했거나 delete등 데이터를 변경했던 사항들을 ItemList.txt파일에 저장
7. 실행 종료

특이사항 
- strtok strlen같은 c++라이브러리 함수 사용없이 직접 my_tok(strtok) 나 my_len(strlen)을 구현하여 수행하였음 