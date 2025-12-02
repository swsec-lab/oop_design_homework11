# Smart 포인터 및 Adapter 패턴 실습

## 📌 개요
- `my_shared_ptr` 클래스를 직접 구현하여 `shared_ptr`와 `unique_ptr`의 동작 과정을 이해합니다.
- Adapter 패턴을 이용하여 기존 게임 코드에 Undead 캐릭터를 추가합니다.

---

## 1️⃣ my_unique_ptr 클래스 구현 (my_smart_ptr.h)

### 구현할 메소드
1. **이동 생성자**:  `my_unique_ptr(my_unique_ptr&& other)`
   - 다른 `my_unique_ptr`이 관리하는 자원의 소유권을 가져옵니다.

2. **이동 대입 연산자**: `operator=(const my_shared_ptr& other)`
   - 자기 자신과 비교 후, 다른 `my_unique_ptr`이 관리하는 자원의 소유권을 가져옵니다.

3. **release()**
   - 내부 포인터를 반환하고, ptr은 nullptr로 초기화 합니다. 


---

## 2️⃣ my_shared_ptr 클래스 구현 (my_smart_ptr.h)

### 구현할 메소드
1. **복사 생성자**: `my_shared_ptr(const MySharedPtr& other)`
   - 다른 `my_shared_ptr`의 포인터와 참조 카운트를 복사합니다.
   - 참조 카운트를 1 증가시킵니다.

2. **대입 연산자**: `operator=(const my_shared_ptr& other)`
   - 자기 자신과 비교 후, 기존 리소스를 `release()`로 정리합니다.
   - 새로운 포인터와 참조 카운트를 복사합니다.
   - 참조 카운트를 1 증가시킵니다.

3. **release()**
   - 내부 전용 메서드입니다.
   - 참조 카운트를 감소시키고, 0이면 관리하는 객체와 참조 카운트 메모리를 삭제합니다.

---


## 3️⃣ Adapter 패턴 구현 

기존 Undead 코드를 Character 코드와 호환될 수 있도록 Adapter 코드를 작성합니다.

### 구현할 코드 (undead.h)
1. 생성자 UndeadAdapter(Undead* u)
   - Undead 객체를 내부 포인터로 저장합니다.
   - Character의 description과 type을 Undead의 이름에 따라 설정합니다.
   - Character의 type은 character.h에 정의된 CharacterType을 참조하세요.

2. getAttack()
   - Character의 공격력은 Undead의 power() 값과 동일합니다.

3. getSpeed()
   - Character의 속도는 Undead의 agility() 값과 동일합니다.

4. getDefense()
   - Character의 방어력은 Undead의 endurance() 값과 동일합니다.

### 구현할 코드 (main.cpp)
1. UndeadAdapter를 이용해서 doTest3() 함수의 TODO 코드를 완성하세요.
   ```
    /* TODO */
    // Zombie 캐릭터를 players에 추가
    // Skeleton 캐릭터를 players에 추가
    // Lich 캐릭터를 players에 추가
   ```
---

## 생각해 보기
- my_unique_ptr에서 복사 생성자와 복사 대입 연산자를 delete한 이유는 무엇일까요?
- stl::sort()를 이용해 캐릭터 인스턴스를 공격력/방어력 순서로 정렬하기 위해서 어떤 코드를 추가해야 할까요?


## 🧪 테스트 방법

모든 함수 구현 후, 아래 명령어를 통해 테스트를 실행하세요:

Windows:
```bash
./test11.bat
```
MacOS/Linux:
```bash
/bin/bash test11.sh
```

