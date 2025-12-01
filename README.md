# Smart 포인터 및 Adapter 패턴 실습

## 📌 개요
- `MySharedPtr` 클래스를 직접 구현하여 `shared_ptr`의 동작 과정을 이해합니다.
- Adapter 패턴을 이용하여 기존 게임 코드에 Undead 캐릭터를 추가합니다.

---

## 1️⃣ MySharedPtr 클래스 구현 (MySharedPtr.h)

### 구현할 메소드
1. **복사 생성자**: `MySharedPtr(const MySharedPtr& other)`
   - 다른 `MySharedPtr`의 포인터와 참조 카운트를 복사합니다.
   - 참조 카운트를 1 증가시킵니다.

2. **대입 연산자**: `operator=(const MySharedPtr& other)`
   - 자기 자신과 비교 후, 기존 리소스를 `release()`로 정리합니다.
   - 새로운 포인터와 참조 카운트를 복사합니다.
   - 참조 카운트를 1 증가시킵니다.

3. **release()**
   - 내부 전용 메서드입니다.
   - 참조 카운트를 감소시키고, 0이면 관리하는 객체와 참조 카운트 메모리를 삭제합니다.
   - 소멸자에서 호출됩니다.

---

## 2️⃣ Adapter 패턴 구현 (undead.h)

기존 Undead 코드를 Character 코드와 호환될 수 있도록 Adapter 코드를 작성합니다.

### 구현할 코드
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


---


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

