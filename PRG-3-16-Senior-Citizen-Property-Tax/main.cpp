//
//  main.cpp
//  PRG-3-16-Senior-Citizen-Property-Tax
//
//  Created by Keith Smith on 10/6/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Madison County provides a $5,000 homeowner exemption for its senior citizens. For
//  example, if a senior's house is valued at $158,000, its assessed value would be $94,800,
//  as explained above. However, he would only pay tax on $89,800. At last year's tax
//  rate of $2.64 for each $100 of assessed value, the property tax would be $2,370.22. In
//  addition to the tax break, senior citizens are allowed to pay their property tax in four
//  equal payments. The quarterly payment due on this property would be $592.68. Write
//  a program that asks the user to input the actual value of a piece of property and the
//  current tax rate for each $100 of assessed value. The program should then calculate
//  and report how much annual property tax a senior homeowner will be charged for this
//  property, and what the quarterly tax bill will be.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const float FLT_ASSESSMENT_PERCENTAGE = 0.60f,
    FLT_HOMEOWNER_EXEMPTION = 5000.00f;
                // FLT_TAX_RATE = 0.0264f; //Calculated from $2.64 / $100
    
    float fltValueHome,
          fltValueAssessed,
          fltValueAdjusted,
          fltTaxPerValue,
          fltTaxRate,
          fltTaxTotal,
          fltTaxQuarterly;
    
    cout << "Please enter the total value of your home: " << endl << "$";
    cin >> fltValueHome;
    while(!cin || fltValueHome < 0.0f || fltValueHome > 10000000.0f)
    {
        cout << "Please enter a value between $0.00 and $10,000,000.00:\n";
        cout << "$";
        cin.clear();
        cin.ignore();
        cin >> fltValueHome;
    }
    
    cout << "Please enter this years tax per $100.00: " << endl << "$";
    cin >> fltTaxPerValue;
    while(!cin || fltTaxPerValue < 0.0f || fltTaxPerValue > 100.0f)
    {
        cout << "Please enter a value between $0.00 and $100.00:\n";
        cout << "$";
        cin.clear();
        cin.ignore();
        cin >> fltTaxPerValue;
    }
    
    fltTaxRate = fltTaxPerValue / 100.0f;
    fltValueAssessed = fltValueHome * FLT_ASSESSMENT_PERCENTAGE;
    fltValueAdjusted = fltValueAssessed - FLT_HOMEOWNER_EXEMPTION;
    fltTaxTotal = fltValueAdjusted * fltTaxRate;
    fltTaxQuarterly = fltTaxTotal / 4.0f;
    
    cout << "For a house with a total value of: $" << setprecision(2) << fixed << fltValueHome << endl;
    cout << "Your assessment value is: $" << fltValueAssessed << endl;
    cout << "Your adjusted value for taxation purposes is: $" << fltValueAdjusted << endl;
    cout << "Your annual tax burden is: $" << fltTaxTotal << endl;
    cout << "Your quarterly tax dues are: $" << fltTaxQuarterly << endl;
    
    return 0;
}


