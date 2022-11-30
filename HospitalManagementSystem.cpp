#include<iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#define SIZE 100

using namespace std;

class AmbulanceService
{
   private:
   string address;
   public:
   void getAmbulance()
   {
      cout<<"Enter the Address at which you want the ambulance"<<endl;
      cin>>address;
      cout<<"Sending an ambulance right away"<<endl;
   }
   

}; 

class Beds{
   private:
   int bed_price;
   int vacant_beds;

   public:
   Beds()
   {
      vacant_beds=SIZE+1;
      
   }
   int occupyBed()
   {
      if(vacant_beds>0)
      --vacant_beds;
      return vacant_beds;
   }
   void emptyBed()
   {
      ++vacant_beds;
   }
   void emergencyWard()
   {
      cout<<"Patient has been admitted into the emergency ward"<<endl;

   }


};


class Patient{
private:
   string name;
   string contact;
   string blood_group;

public:

   vector<string> enterPatientDetails()
   {
      cout<<"Enter Patient Name"<<endl;
      cin>>name;
      cout<<"Enter Patient contact number"<<endl;
      cin>>contact;
      cout<<"Enter Patient blood group"<<endl;
      cin>>blood_group;

      vector<string> p_details;
      p_details.push_back(name);
      p_details.push_back(contact);
      p_details.push_back(blood_group);

      return p_details;
   }
   
   
   
};

class Bill{
   private:

   int consultationfeecharge;
   int hospital_care_charge;
   int medicinecharge;
   int totalamount;

   public:
   
   Bill()
   {
      consultationfeecharge =0;
      hospital_care_charge = 0;
      medicinecharge = 0;
      totalamount = 0;
   }
   void printReceipt(int i)
   {
      consultationfeecharge = (i+2)*1000;
      hospital_care_charge = (i+2)*(i+2)*1000;
      medicinecharge = (i+2)*(i+2)*(i+2)*1000;
      totalamount = consultationfeecharge + hospital_care_charge + medicinecharge;
      cout << "\n BILL\n";
      
      cout << "Consultation Fee:     \t" << consultationfeecharge << endl;
      cout << "Hospital Care Charge: \t" << hospital_care_charge << endl;
      cout << "Medicines Fee:        \t" << medicinecharge << endl;
      cout << "\nTotal:                \t" << totalamount << endl;
      
   }

};

class AvailService;

class Hospital{
   private: 

   friend AvailService;
   string id;

   int doc_count;
   int staff_count;
   int empty_beds;
   int totalbed;
   int xyz;
   string hospital_name;
   string contact;

   string patient_id[SIZE];
   string patient_name[SIZE];
   int patient_roomNo[SIZE];
   string patient_bloodgrp[SIZE];
   string patient_contactno[SIZE];
   int idcount;

   string relievingdate;

   public:

   Patient p;
   Bill b;


   Hospital()
   {
      id="HMS2022_";
      idcount=1;
      doc_count=20;
      staff_count=40;
      empty_beds=SIZE;
      hospital_name="Apollo Hospital";
      contact="+91-0242-66891";
      for(int i=0;i<SIZE;i++)
         patient_roomNo[i]=0;
   }
   
   void feedHospitalDetails()
   {
      ifstream fileName("/Users/rishabhlalwani/Documents/GitHub/HospitalManagementSystem/HospitalManagementSystem-1/hospitaldetails.txt");
      string eachLine;
      string word;
      int j=0;
      while (getline (fileName, eachLine)) 
      {
         stringstream X(eachLine); 
         
         int turn=1;
         while (getline(X, word, ' '))
         {
            switch(turn)
            {
               case 1:patient_name[j]=word; break;
               case 2:patient_id[j]=word;   break;
               case 3:patient_roomNo[j]=stoi(word);break;
               case 4:patient_bloodgrp[j]=word; break;
               case 5: patient_contactno[j]=word;break;
            }
         ++turn;  

         }
         ++j;
         ++idcount;
      }
      fileName.close();
      
   }
   
   void printHospitalDetails()
   {
      cout<<"Hospital: "<<hospital_name<<endl;
      cout<<"Contact No:  "<<contact<<endl;
      cout<<"Number of Doctors in this Hospital is: "<<doc_count<<endl;
      cout<<"Staff Count of this Hospital is : "<<staff_count<<endl;
      cout<<"Number of beds available in the hospital are "<<SIZE<<endl;

   }
   void admitPatient()
   {
      Beds bed;
      Patient p1;
      int admission_ward;
      vector <string> patient_details;
      cout<<" Enter 1 for Emergency Admission, 2 for Non-Emergency Admission"<<endl;
      cin>>admission_ward;

         if(admission_ward==1)
         bed.emergencyWard();
         
         empty_beds=bed.occupyBed();

         if(empty_beds>0)
         {
            for(int i=0;i<SIZE;i++)
            {
               if(patient_roomNo[i]==0)
               {
                  ++idcount;
                  //cout<<id<<endl;
                  patient_id[i]=id;
                  patient_roomNo[i]=i+1;
                  patient_id[i]=id+to_string(idcount);
                  
                  patient_details=p1.enterPatientDetails();
                  patient_name[i]=patient_details[0];
                  patient_contactno[i]=patient_details[1];
                  patient_bloodgrp[i]=patient_details[2];

                  cout << "Patient has been admitted in room no. " << patient_roomNo[i] << endl;
                  break;
               }
            }
         }
         else{
            cout<<"No empty bed is available"<<endl;
         }
         /* Finite beds  for non-emergency admission. Hospital takes any number of patients for emergency admission */
   }
   void printPatientDetails(string name)
   {
      bool found=false;
      for(int i=0;i<SIZE;i++)
            {
               if(patient_name[i]==name)
               {
                  found=true;
                  cout<<"Name: "<<patient_name[i]<<endl;
                  cout<<"Id: "<<patient_id[i]<<endl;
                  cout<<"RoomNo: "<<patient_roomNo[i]<<endl;
                  cout<<"ContactNo: "<<patient_contactno[i]<<endl;
                  cout<<"BloodGrp: "<<patient_bloodgrp[i]<<endl;
                  break;
               }
            }
            if(found==false)
               cout<<"No patient with given name is admitted in the hospital"<<endl;
            
   }
   void dischargePatient()
   {
      string temp;
      cout << "Enter patient Name\n";
      cin>> temp;
      int temp2;
      for(int i=0 ; i<SIZE ; i++)
      {
         if(patient_name[i] == temp){temp2 = i; break;}
      }

      b.printReceipt(temp2);
      
      patient_name[temp2] = "";
      patient_roomNo[temp2] = 0;
      patient_bloodgrp[temp2] = "";
      patient_contactno[temp2] = "";
      patient_id[temp2] = "";
      cout << "Patient discharged\n";

   }   
};

class AvailService
{
public:
   AmbulanceService obj2;
   
   void availService(Hospital &hospital)
   {

      
      cout<<"Enter the service you want to avail"<<endl;
      cout<<" 1: Admit a Patient"<<endl;
      cout<<" 2: Collect a Discharged Patient"<<endl;
      cout<<" 3: Avail Ambulance Service"<<endl;
      cout<<" 4: Print Patient Details"<<endl;
      int choice;
      cin>>choice;
      switch(choice)
      {
         case 1: hospital.admitPatient();break;
         case 2: hospital.dischargePatient();break;
         case 3: obj2.getAmbulance();break;
         case 4: 
               cout<<"Enter Patient Name"<<endl;
               string name;
               cin>>name;
               hospital.printPatientDetails(name);break;
      }

   }
};






int main()
{
   AvailService service;
   Hospital hospital;
   Patient p;
   hospital.printHospitalDetails();
   hospital.feedHospitalDetails();
   
   cout<<"Enter number of services you want to avail"<<endl;
   int num;
   cin>>num;
   for(int i=1;i<=num;i++)
   {
      service.availService(hospital);
   }
   return 0;
}