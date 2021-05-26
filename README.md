# HR-Database-Management-System
This is a simple HR application using the C++ and Oracle. This application can help user to display, insert, update, and delete the employees’ information.


# Program Demo
```
********************* HR Menu *********************
1)      Find Employee
2)      Employees Report
3)      Add Employee
4)      Update Employee
5)      Remove Employee
0)      Exit
Enter an option (0-5): 1
Enter Employee Number: 1002

-------------- Employee Information -------------
Employee Number: 1002
Last Name : Murphy
First Name : Diane
Extension : x5800
Email : dmurphy@classicmodelcars.com
Office Code : 1
Manager ID : 0
Job Title : President

********************* HR Menu *********************
1)      Find Employee
2)      Employees Report
3)      Add Employee
4)      Update Employee
5)      Remove Employee
0)      Exit
Enter an option (0-5): 1
Enter Employee Number: 1078
Employee 1078 does not exist.

********************* HR Menu *********************
1)      Find Employee
2)      Employees Report
3)      Add Employee
4)      Update Employee
5)      Remove Employee
0)      Exit
Enter an option (0-5): 2

------   ---------------    ---------------------------------   ----------------   ---------   -----------------
ID       Employee Name      Email                               Phone              Extension   Manager Name
------   ---------------    ---------------------------------   ----------------   ---------   -----------------
1002     Diane Murphy       dmurphy@classicmodelcars.com        +1 650 219 4782    x5800
1056     Mary Patterson     mpatterso@classicmodelcars.com      +1 650 219 4782    x4611       Diane Murphy
1076     Jeff Firrelli      jfirrelli@classicmodelcars.com      +1 650 219 4782    x9273       Diane Murphy
1088     William Patterson  wpatterson@classicmodelcars.com     +61 2 9264 2451    x4871       Mary Patterson
1102     Gerard Bondur      gbondur@classicmodelcars.com        +33 14 723 4404    x5408       Mary Patterson
1143     Anthony Bow        abow@classicmodelcars.com           +1 650 219 4782    x5428       Mary Patterson
1165     Leslie Jennings    ljennings@classicmodelcars.com      +1 650 219 4782    x3291       Anthony Bow
1166     Leslie Thompson    lthompson@classicmodelcars.com      +1 650 219 4782    x4065       Anthony Bow
1188     Julie Firrelli     jfirrelli@classicmodelcars.com      +1 215 837 0825    x2173       Anthony Bow
1216     Steve Patterson    spatterson@classicmodelcars.com     +1 215 837 0825    x4334       Anthony Bow
1286     Foon Yue Tseng     ftseng@classicmodelcars.com         +1 212 555 3000    x228        Anthony Bow
1323     George Vanauf      gvanauf@classicmodelcars.com        +1 212 555 3000    x4102       Anthony Bow
1337     Loui Bondur        lbondur@classicmodelcars.com        +33 14 723 4404    x6493       Gerard Bondur
1370     Gerard Hernandez   ghernande@classicmodelcars.com      +33 14 723 4404    x2028       Gerard Bondur
1401     Pamela Castillo    pcastillo@classicmodelcars.com      +33 14 723 4404    x2759       Gerard Bondur
1501     Larry Bott         lbott@classicmodelcars.com          +44 20 7877 2041   x2311       Gerard Bondur
1504     Barry Jones        bjones@classicmodelcars.com         +44 20 7877 2041   x102        Gerard Bondur
1611     Andy Fixter        afixter@classicmodelcars.com        +61 2 9264 2451    x101        William Patterson
1612     Peter Marsh        pmarsh@classicmodelcars.com         +61 2 9264 2451    x102        William Patterson
1619     Tom King           tking@classicmodelcars.com          +61 2 9264 2451    x103        William Patterson
1621     Mami Nishi         mnishi@classicmodelcars.com         +81 33 224 5000    x101        Mary Patterson
1625     Yoshimi Kato       ykato@classicmodelcars.com          +81 33 224 5000    x102        Mami Nishi
1702     Martin Gerard      mgerard@classicmodelcars.com        +33 14 723 4404    x2312       Gerard Bondur

********************* HR Menu *********************
1) Find Employee
2) Employees Report
3) Add Employee
4) Update Employee
5) Remove Employee
0) Exit
Enter an option (0-5): 3
-------------- New Employee Information -------------
Employee Number : 1099
Last Name : Adam
First Name : Sarah
Extension : x2222
Email : s@email.com
Office Code : 1
Manager ID : 1002
Job Title : Cashier
The new employee is added successfully.

********************* HR Menu *********************
1) Find Employee
2) Employees Report
3) Add Employee
4) Update Employee
5) Remove Employee
0) Exit
Enter an option (0-5): 3
-------------- New Employee Information -------------
Employee Number : 1088
Last Name : Adam
First Name : Sarah
Extension : x2222
Email : s@email.com
Office Code : 1
Manager ID : 1002
Job Title : Cashier
An employee with the same employee number exists.

********************* HR Menu *********************
1) Find Employee
2) Employees Report
3) Add Employee
4) Update Employee
5) Remove Employee
0) Exit
Enter an option (0-5): 4
Employee Number: 1099
Last Name: Adam
First Name: Sarah
Extension: x6666
The employee's extension is updated successfully.

********************* HR Menu *********************
1) Find Employee
2) Employees Report
3) Add Employee
4) Update Employee
5) Remove Employee
0) Exit
Enter an option (0-5): 4
Employee Number: 1000
The employee with ID 1000 does not exist.

********************* HR Menu *********************
1) Find Employee
2) Employees Report
3) Add Employee
4) Update Employee
5) Remove Employee
0) Exit
Enter an option (0-5): 5
Employee Number: 1099
The employee with ID 1099 is deleted successfully.

********************* HR Menu *********************
1) Find Employee
2) Employees Report
3) Add Employee
4) Update Employee
5) Remove Employee
0) Exit
Enter an option (0-5): 5
Employee Number: 1000
The employee with ID 1000 does not exist.

********************* HR Menu *********************
1) Find Employee
2) Employees Report
3) Add Employee
4) Update Employee
5) Remove Employee
0) Exit
Enter an option (0-5): 0

Thanks for using DBS211_GROUP10 HR SYSTEM. Exiting...

```
