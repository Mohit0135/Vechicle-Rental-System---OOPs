# Vechicle-Rental-System---OOPs
This project demonstrates the Fundamentls of Object Oriented Programming.

-------------------------- OVERVIEW of the PROJECT  with the defination of each pillar of OOPs -------------------------------

Classes:
Vehicle: This is the base class representing a generic vehicle. It contains common attributes and methods shared by all vehicles, such as vehicle ID, model, manufacturer, rental cost, etc.
1- Car: Inherits from Vehicle class. It adds specific attributes and methods relevant to cars, such as number of seats, fuel type, etc.
2- Bike: Inherits from Vehicle class. It adds specific attributes and methods relevant to bikes, such as engine capacity, type of bike, etc.
3- Customer: This class represents a customer renting a vehicle. It contains attributes like customer ID, name, contact information, rented vehicle, rental duration, etc.
4- RentalAgency: This class manages the rental operations. It contains methods for renting vehicles, returning vehicles, calculating rental charges, maintaining inventory, etc.

Encapsulation:
Encapsulation is the bundling of data and methods that operate on the data into a single unit, called a class. It restricts access to some of the object's components, preventing direct modification of data and implementation details from the outside. 
Encapsulation helps in achieving data hiding and abstraction.
Here, Each class encapsulates its data members (attributes) and member functions (methods) within itself. Access to these members is controlled through public, private, and protected access specifiers to enforce data hiding and protect data integrity.

Inheritance:
Inheritance is the mechanism by which one class can inherit properties and behavior from another class. 
It allows a new class (derived class or subclass) to inherit attributes and methods from an existing class (base class or superclass). 
This promotes code reusability and helps in building a hierarchical class structure.
Here, Car and Bike classes inherit common attributes and methods from the Vehicle class. This avoids redundancy and promotes code reusability.
The RentalAgency class might also utilize inheritance if there are different types of rental agencies (e.g., luxury car rental, bike rental, etc.).

Polymorphism:
Polymorphism is demonstrated through method overriding. For example, both Car and Bike classes might override a method like calculateRentalCost() to implement specific logic for rental cost calculation based on the vehicle type.
Another example is a method like displayDetails(), which can be overridden in each subclass to display specific details of the vehicle.

Abstraction:
Polymorphism allows objects of different classes to be treated as objects of a common superclass. 
It enables a single interface to represent different underlying forms (data types or classes). 
There are two types of polymorphism: compile-time (method overloading) and runtime (method overriding).
Polymorphism simplifies code and makes it more flexible and extensible.
Here, the implementation of classes hides the internal complexities of the system from the user. Users interact with simple and intuitive interfaces provided by the classes.
For example, the RentalAgency class abstracts away the details of managing the inventory and rental process, providing simple methods for renting and returning vehicles.

Other Features:
Abstraction is the process of hiding the complex implementation details and showing only the essential features of the object. 
It focuses on what an object does rather than how it does it. 
Abstraction allows developers to create a simple model representing a complex real-world system. It enhances code readability, reduces complexity, and facilitates code maintenance and modification.
Here, The system can include features like adding new vehicles to the inventory, updating rental prices, searching for available vehicles based on criteria, generating rental invoices, etc.
Error handling mechanisms can be implemented to handle exceptions such as invalid inputs, unavailable vehicles, etc.
