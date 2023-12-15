public class Week7Practice {

  private static class A {

    public int v;

    public A(int v) {
      this.v = v;
    }
  }

  public static void swap(A a1, A a2) {
    A tmp = a1;
    a1 = a2;
    a2 = tmp;
    System.out.println("swap() - A1:" + a1);
    System.out.println("swap() - A2:" + a2);
  }

  public static void real_swap(A a1, A a2) {
    int tmp = a1.v;
    a1.v = a2.v;
    a2.v = tmp;
  }

  public static void main(String[] args) {
    //Sometimes Call-by-Reference won't work in Java.
    //What are the values of a1 and a2?
    A a1 = new A(10);
    A a2 = new A(5);
    System.out.println("A1:" + a1);
    System.out.println("A2:" + a2);
    swap(a1, a2);
    System.out.println("A1:" + a1);
    System.out.println("A2:" + a2);

    //Implement the real_swap() to actually swap the values.
    real_swap(a1, a2);
    System.out.println("A1:" + a1.v);
    System.out.println("A2:" + a2.v);

    //Here are examples of implicit/explicit conversion.
    Parent p = new Child(); //implicit, upcasting. p는 Parent의 멤버 변수나 함수에만 접근 가능
    Parent p1 = new Parent();
    Child c = (Child) p; //explicit, downcasting. c는 Parent, Child의 멤버 변수나 함수에 접근 가능
        /*
        Write your own examples to reveal differences among the above cases.
         - You may print out values of fields, add methods to the classes, etc.
        Breifly explain your examples
         - what is the difference and why the examples show such behaviour?

        ex)
        - Is it okay to access p.y?
            System.out.println(p.y);
        - Is it possible to cast?
            Child c1 = (Child) p1;
        */

    System.out.println("p.x: " + p.x); // p를 통해 부모 클래스의 멤버 변수인 x는 접근 가능 
    // System.out.println("p.y: " + p.y); // Error: p를 통해 자식 클래스의 멤버 변수인 y는 접근 불가능, 컴파일 시 에러

    System.out.println("c.y: " + c.y); // p는 내부적으로 자식 클래스를 구현하고 있으므로 변환 가능
    // Child c1 = (Child) p1; // Error: 부모 클래스로부터 자식 클래스는 변환 불가능, 런타임 시 에러
  }

  public static class Parent {

    public int x = 1;
  }

  public static class Child extends Parent {

    public int y = 2;

    public Child() {
      x = 3;
    }
  }
}
