# Notes

Java programming language was originally developed by Sun Microsystems which was initiated by James Gosling and released in 1995 as core component of Sun Microsystems' Java platform

<ul class="list">
<li><p><b>Object Oriented</b> − In Java, everything is an Object. Java can be easily extended since it is based on the Object model.</p></li>
<li><p><b>Platform Independent</b> − Unlike many other programming languages including C and C++, when Java is compiled, it is not compiled into platform specific machine, rather into platform independent byte code. This byte code is distributed over the web and interpreted by the Virtual Machine (JVM) on whichever platform it is being run on.</p></li>
<li><p><b>Simple</b> − Java is designed to be easy to learn. If you understand the basic concept of OOP Java, it would be easy to master.</p></li>
<li><p><b>Secure</b> − With Java's secure feature it enables to develop virus-free, tamper-free systems. Authentication techniques are based on public-key encryption.</p></li>
<li><p><b>Architecture-neutral</b> − Java compiler generates an architecture-neutral object file format, which makes the compiled code executable on many processors, with the presence of Java runtime system.</p></li>
<li><p><b>Portable</b> − Being architecture-neutral and having no implementation dependent aspects of the specification makes Java portable. Compiler in Java is written in ANSI C with a clean portability boundary, which is a POSIX subset.</p></li>
<li><p><b>Robust</b> − Java makes an effort to eliminate error prone situations by emphasizing mainly on compile time error checking and runtime checking.</p></li>
<li><p><b>Multithreaded</b> − With Java's multithreaded feature it is possible to write programs that can perform many tasks simultaneously. This design feature allows the developers to construct interactive applications that can run smoothly.</p></li>
<li><p><b>Interpreted</b> − Java byte code is translated on the fly to native machine instructions and is not stored anywhere. The development process is more rapid and analytical since the linking is an incremental and light-weight process.</p></li>
<li><p><b>High Performance</b> − With the use of Just-In-Time compilers, Java enables high performance.</p></li>
<li><p><b>Distributed</b> − Java is designed for the distributed environment of the internet.</p></li>
<li><p><b>Dynamic</b> − Java is considered to be more dynamic than C or C++ since it is designed to adapt to an evolving environment. Java programs can carry extensive amount of run-time information that can be used to verify and resolve accesses to objects on run-time.</p></li>
</ul>

Here are some quick differences between java and c++

- java is machine independent where are c++ is machine dependent
- C++ supports multiple inheritance where are java don't support
- C++ is compiled language where as java is interpreted language
- C++ supports virtual keyword java don't support
- java is multi-threaded support in C++ 3rd party libraries are used
- java does not support pass by reference

JRE is a Java Runtime Environment which is the implementation of JVM i.e. the specifications that are defined in JVM are implemented and create a corresponding environment for the execution of code. JRE comprises mainly Java binaries and other classes to execute the program like JVM which physically exists. Along with Java binaries JRE also consists of various technologies of deployment, user interfaces to interact with code executed, some base libraries for different functionalities, and language and util-based libraries

JVM is the abbreviation for Java Virtual Machine which is a specification that provides a runtime environment in which Java byte code can be executed

JVM is the abbreviation for Java Virtual Machine which is a specification that provides a runtime environment in which Java byte code can be executed

Object-Oriented Programming is a methodology or paradigm to design a program using classes and objects. It simplifies software development and maintenance by providing some concepts.an object is an entity that has two characteristics (states and behavior)

In object-oriented programming, a class is a blueprint from which individual objects are created

The term "polymorphism" means "many forms". In object-oriented programming, polymorphism is useful when you want to create multiple forms with the same name of a single entity.

The method overloading is performed in the same class where we have multiple methods with the same name but different parameters, whereas, the method overriding is performed by using the inheritance where we can have multiple methods with the same name in parent and child classes.

In object-oriented programming, an abstraction is a technique of hiding internal details and showing functionalities. The abstract classes and interfaces are used to achieve abstraction in Java.

In an object-oriented approach, encapsulation is a process of binding the data members (attributes) and methods together. The encapsulation restricts direct access to important data. The best example of the encapsulation concept is making a class where the data members are private and methods are public to access through an object. In this case, only methods can access those private data.

<ul class="list">
<li>A class does not take any byte of memory.</li>
<li>A class is just like a real-world entity, but it is not a real-world entity. It's a blueprint where we specify the functionalities.</li>
<li>A class contains mainly two things: Methods and Data Members.</li>
<li>A class can also be a nested class.</li>
<li>Classes follow all of the rules of OOPs such as inheritance, encapsulation, abstraction, etc.</li>
</ul>

<ul class="list">
<li><p><b>Local variables</b> − Variables defined inside methods, constructors or blocks are called local variables. The variable will be declared and initialized within the method and the variable will be destroyed when the method has completed.</p></li>
<li><p><b>Instance variables</b> − Instance variables are variables within a class but outside any method. These variables are initialized when the class is instantiated. Instance variables can be accessed from inside any method, constructor or blocks of that particular class.</p></li>
<li><p><b>Class variables</b> − Class variables are variables declared within a class, outside any method, with the static keyword.</p></li>
</ul>

<ul class="list">
<li><p>There can be only one public class per source file.</p></li>
<li><p>A source file can have multiple non-public classes.</p></li>
<li><p>The public class name should be the name of the source file as well which should be appended by <b>.java</b> at the end. For example − the class name is <i>public class Employee{}</i> then the source file should be as Employee.java.</p></li>
<li><p>If the class is defined inside a package, then the package statement should be the first statement in the source file.</p></li>
<li><p>If import statements are present, then they must be written between the package statement and the class declaration. If there are no package statements, then the import statement should be the first line in the source file.</p></li>
<li><p>Import and package statements will imply to all the classes present in the source file. It is not possible to declare different import and/or package statements to different classes in the source file.</p></li>
</ul>

```java
import java.io.*;
public class Employee {

   String name;
   int age;
   String designation;
   double salary;

   // This is the constructor of the class Employee
   public Employee(String name) {
      this.name = name;
   }

   // Assign the age of the Employee  to the variable age.
   public void empAge(int empAge) {
      age = empAge;
   }

   /* Assign the designation to the variable designation.*/
   public void empDesignation(String empDesig) {
      designation = empDesig;
   }

   /* Assign the salary to the variable	salary.*/
   public void empSalary(double empSalary) {
      salary = empSalary;
   }

   /* Print the Employee details */
   public void printEmployee() {
      System.out.println("Name:"+ name );
      System.out.println("Age:" + age );
      System.out.println("Designation:" + designation );
      System.out.println("Salary:" + salary);
   }
}

```

You can also make the class attributes read-only by using the final keyword after the access modifier while declaring an attribute.

this is a keyword in Java which is used as a reference to the object of the current class, with in an instance method or a constructor. Using this you can refer the members of a class such as constructors, variables and methods.

There are two types of class methods public and static class method. The public class methods are accessed through the objects whereas, the static class methods are accessed are accesses without an object. You can directly access the static methods.

It is possible to define a method that will be called just before an object's final destruction by the garbage collector. This method is called finalize( ), and it can be used to ensure that an object terminates cleanly.

For example, you might use finalize( ) to make sure that an open file owned by that object is closed.

To add a finalizer to a class, you simply define the finalize( ) method. The Java runtime calls that method whenever it is about to recycle an object of that class.

Inside the finalize( ) method, you will specify those actions that must be performed before an object is destroyed.

<ul>
<li>The name of the constructors must be the same as the class name.</li>
<li>Java constructors do not have a return type. Even do not use void as a return type.</li>
<li>There can be multiple constructors in the same class, this concept is known as constructor overloading.</li>
<li>The <a href="/java/java_access_modifiers.htm" target="_blank">access modifiers</a> can be used with the constructors, use if you want to change the visibility/accessibility of constructors.</li>
<li>Java provides a default constructor that is invoked during the time of object creation. If you create any type of constructor, the default constructor (provided by Java) is not invoked.</li>
</ul>

A variable or method declared without any access control modifier is available to any other class in the same package. The fields in an interface are implicitly public static final and the methods in an interface are by default public.

Variables, methods, and constructors, which are declared protected in a superclass can be accessed only by the subclasses in other package or any class within the package of the protected members' class.

Inheritance is a process where one class acquires the properties (methods and attributes) of another. With the use of inheritance, the information is made manageable in a hierarchical order.

Super keyword

- It is used to differentiate the members of superclass from the members of subclass, if they have same names.

- It is used to invoke the superclass constructor from subclass

```java
class Super_class {
   int num = 20;

   // display method of superclass
   public void display() {
      System.out.println("This is the display method of superclass");
   }
}

public class Sub_class extends Super_class {
   int num = 10;

   // display method of sub class
   public void display() {
      System.out.println("This is the display method of subclass");
   }

   public void my_method() {
      // Instantiating subclass
      Sub_class sub = new Sub_class();

      // Invoking the display() method of sub class
      sub.display();

      // Invoking the display() method of superclass
      super.display();

      // printing the value of variable num of subclass
      System.out.println("value of the variable named num in sub class:"+ sub.num);

      // printing the value of variable num of superclass
      System.out.println("value of the variable named num in super class:"+ super.num);
   }

   public static void main(String args[]) {
      Sub_class obj = new Sub_class();
      obj.my_method();
   }
}
```

An aggregation is a relationship between two classes where one class contains an instance of another class

```java

// Java Example: Run Time Polymorphism
class Vehicle {
  public void displayInfo() {
    System.out.println("Some vehicles are there.");
  }
}

class Car extends Vehicle {
  // Method overriding
  @Override
  public void displayInfo() {
    System.out.println("I have a Car.");
  }
}

class Bike extends Vehicle {
  // Method overriding
  @Override
  public void displayInfo() {
    System.out.println("I have a Bike.");
  }
}

public class Main {
  public static void main(String[] args) {
    Vehicle v1 = new Car(); // Upcasting
    Vehicle v2 = new Bike(); // Upcasting

    // Calling the overridden displayInfo() method of Car class
    v1.displayInfo();

    // Calling the overridden displayInfo() method of Bike class
    v2.displayInfo();
  }
}

```

<ul class="list">
<li><p>The argument list should be exactly the same as that of the overridden method.</p></li>
<li><p>The return type should be the same or a subtype of the return type declared in the original overridden method in the superclass.</p></li>
<li><p>The access level cannot be more restrictive than the overridden method's access level. For example: If the superclass method is declared public then the overridding method in the sub class cannot be either private or protected.</p></li>
<li><p>Instance methods can be overridden only if they are inherited by the subclass.</p></li>
<li><p>A method declared final cannot be overridden.</p></li>
<li><p>A method declared static cannot be overridden but can be re-declared.</p></li>
<li><p>If a method cannot be inherited, then it cannot be overridden.</p></li>
<li><p>A subclass within the same package as the instance's superclass can override any superclass method that is not declared private or final.</p></li>
<li><p>A subclass in a different package can only override the non-final methods declared public or protected.</p></li>
<li><p>An overriding method can throw any uncheck exceptions, regardless of whether the overridden method throws exceptions or not. However, the overriding method should not throw checked exceptions that are new or broader than the ones declared by the overridden method. The overriding method can throw narrower or fewer exceptions than the overridden method.</p></li>
<li><p>Constructors cannot be overridden.</p></li>
</ul>

method overriding:

- Use different number of arguments
- Use different type of arguments

Dynamic binding is also known as run-time polymorphism or late binding. Dynamic binding uses objects to resolve binding.

Abstraction is a process of hiding the implementation details from the user, only the functionality will be provided to the user. In other words, the user will have the information on what the object does instead of how it does it. In Java programming, abstraction is achieved using Abstract classes and interfaces.

A Java class which contains the abstract keyword in its declaration is known as abstract class.

<ul class="list">
<li><p>Java abstract classes may or may not contain <i>abstract methods</i>, i.e., methods without body ( public void get(); )</p></li>
<li><p>But, if a class has at least one abstract method, then the class <b>must</b> be declared abstract.</p></li>
<li><p>If a class is declared abstract, it cannot be instantiated.</p></li>
<li><p>To use an abstract class, you have to inherit it from another class, provide implementations to the abstract methods in it.</p></li>
<li><p>If you inherit an abstract class, you have to provide implementations to all the abstract methods in it.</p></li>
</ul>

If you want a class to contain a particular method but you want the actual implementation of that method to be determined by child classes, you can declare the method in the parent class as an abstract.

Any class inheriting the current class must either override the abstract method or declare itself as abstract.

Encapsulation in Java is a mechanism of wrapping the data (variables) and code acting on the data (methods) together as a single unit. In encapsulation, the variables of a class will be hidden from other classes, and can be accessed only through the methods of their current class. Therefore, it is also known as data hiding.

<ul class="list">
<li><p>Declare the variables of a class as private.</p></li>
<li><p>Provide public setter and getter methods to modify and view the variables values.</p></li>
</ul>

Java interface is a collection of abstract methods. The interface is used to achieve abstraction in which you can define methods without their implementations (without having the body of the methods). An interface is a reference type and is similar to the class.

<ul class="list">
<li><p>You cannot instantiate an interface.</p></li>
<li><p>An interface does not contain any constructors.</p></li>
<li><p>All of the methods in an interface are abstract.</p></li>
<li><p>An interface cannot contain instance fields. The only fields that can appear in an interface must be declared both static and final.</p></li>
<li><p>An interface is not extended by a class; it is implemented by a class.</p></li>
<li><p>An interface can extend multiple interfaces.</p></li>
</ul>

A class uses the implements keyword to implement an interface. The implements keyword appears in the class declaration following the extends portion of the declaration.

```java
/* File name : MammalInt.java */
public class MammalInt implements Animal {

   public void eat() {
      System.out.println("Mammal eats");
   }

   public void travel() {
      System.out.println("Mammal travels");
   }

   public int noOfLegs() {
      return 0;
   }

   public static void main(String args[]) {
      MammalInt m = new MammalInt();
      m.eat();
      m.travel();
   }
}
interface Animal {
   public void eat();
   public void travel();
}

```

The extends keyword is used to extend an interface, and the child interface inherits the methods of the parent interface.

A Java inner class is a class that is defined inside another class. The concept of inner class works with nested Java classes where outer and inner classes are used. The main class in which inner classes are defined is known as the outer class and all other classes which are inside the outer class are known as Java inner classes.

An exception (or exceptional event) is a problem that arises during the execution of a program. When an Exception occurs the normal flow of the program is disrupted and the program/Application terminates abnormally, which is not recommended, therefore, these exceptions are to be handled.

A checked exception is an exception that is checked (notified) by the compiler at compilation-time, these are also called as compile time exceptions. These exceptions cannot simply be ignored, the programmer should take care of (handle) these exceptions.

An unchecked exception is an exception that occurs at the time of execution. These are also called as Runtime Exceptions. These include programming bugs, such as logic errors or improper use of an API. Runtime exceptions are ignored at the time of compilation.

All exception classes are subtypes of the java.lang.Exception class. The exception class is a subclass of the Throwable class. Other than the exception class there is another subclass called Error which is derived from the Throwable class.

Errors are abnormal conditions that happen in case of severe failures, these are not handled by the Java programs. Errors are generated to indicate errors generated by the runtime environment. Example: JVM is out of memory. Normally, programs cannot recover from errors.

The Exception class has two main subclasses: IOException class and RuntimeException Class.

A method catches an exception using a combination of the try and catch keywords. A try/catch block is placed around the code that might generate an exception. Code within a try/catch block is referred to as protected code, and the syntax for using try/catch looks like the

A try block can be followed by multiple catch blocks.

```java
try {
   file = new FileInputStream(fileName);
   x = (byte) file.read();
} catch (IOException i) {
   i.printStackTrace();
   return -1;
} catch (FileNotFoundException f) // Not valid! {
   f.printStackTrace();
   return -1;
}
```

If a method does not handle a checked exception, the method must declare it using the throws keyword. The throws keyword appears at the end of a method's signature.

You can throw an exception, either a newly instantiated one or an exception that you just caught, by using the throw keyword.

Try to understand the difference between throws and throw keywords, throws is used to postpone the handling of a checked exception and throw is used to invoke an exception explicitly.
