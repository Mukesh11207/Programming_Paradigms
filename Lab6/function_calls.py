def call_by_value(x):
    x = 100
    print("Inside function:", x)

def call_by_address(numbers):
    numbers[0] = 200

def call_by_reference(numbers):
    numbers[0] = 300

def default_parameter(name, age=18):
    print("Name:", name)
    print("Age:", age)

def keyword_parameter(name, age, marks):
    print("Name:", name)
    print("Age:", age)
    print("Marks:", marks)

a = 10

print("Call by Value")
print("Before:", a)
call_by_value(a)
print("After:", a)

print("\nCall by Address")
numbers = [10, 20, 30]
print("Before:", numbers)
call_by_address(numbers)
print("After:", numbers)

print("\nCall by Reference")
numbers = [10, 20, 30]
print("Before:", numbers)
call_by_reference(numbers)
print("After:", numbers)

print("\nDefault Parameter")
default_parameter("Mukesh")

print("\nKeyword Parameter")
keyword_parameter("Mukesh", 18, 95)

