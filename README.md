# Airgead-Banking

# Airgead Banking App Functional Requirements
1. Airgead Banking wants a screen to display with the following information:

• Initial Investment Amount: The starting amount of your investment (a positive real
number)

• Monthly Deposit: The amount you plan to contribute to the growth of your investment
each month (a positive real number)

• Annual Interest (Compounded): Interest that is added to the principal sum of your
investment and its previously accumulated interest (interest on interest and principal)

• Number of Years: The number of years your investment has to grow

• A way to see the data (for example: “Press any key to continue…”)
It should look something like the images below, with the ability to accept input. The first image
shows what the user should see, and the second image shows the user’s values.

![image](https://user-images.githubusercontent.com/110702739/186437742-9c890af6-a736-4023-9ab9-9fd7124b91d0.png)

2. When the user continues, the console should display two static reports. One should show the
year-end balances and year-end earned interest if no additional monthly deposits are made. The
second should show the year-end balances and year-end earned interest based on the monthly
deposit value that was input by the user ($50.00 in this example). The following is an example of
what your interface might look like. It is in no way representative of what it must look like. Be
creative and keep the user experience in mind when designing your solution.

![image](https://user-images.githubusercontent.com/110702739/186438480-4216ec85-24d0-4cef-baa0-5d6e0a9cb207.png)

3. The user should be able to test different monthly deposit amounts, interest rates, and lengths of
time to see how increases and decreases impact their investment growth

4. Your code will need to account for the following:
5. 
a. Month: The number of months based on user input in the “Number of Years” field

b. Opening Amount: The initial investment amount as well as the opening balance each
month, which includes interest

c. Deposited Amount: The dollar amount the user plans to deposit each month. This value
will be the same every month for the duration of the investment.

d. Total: The sum of the opening and deposited amounts

e. Interest: Money earned based on the “annual interest” rate input by the user. The
interest based on an opening amount of $1 and a deposited amount of $50 with an
interest rate of 5% compounded monthly is:
(Opening Amount + Deposited Amount) * ((Interest Rate/100)/12)
OR
(1 + 50) * ((5/100)/12)
Note: Dividing by 100 converts the interest rate percentage to a decimal.
Note: 12 is the number of months in a year. Dividing the yearly amount by twelve gives
monthly compounded interest.

f. Closing Balance: The sum of the total and interest amounts
As an example, this chart illustrates how compound interest is calculated based on an initial
investment amount of $1.00 with additional monthly deposits of $50.00 at 5% interest over 5
years.

