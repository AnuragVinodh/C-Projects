//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <fstream>
#include<cmath>
//////////////////////////////////////////////////////////////
//
// local #includes and function declarations; do not remove
//
using namespace std;
#ifndef MARMOSET_TESTING
#include <iostream>
#endif

//////////////////////////////////////////////////////////////
//
// struct definitions 
//
#ifndef MARMOSET_TESTING
struct Student
{
	int studentID;
	int grade;
};

struct Dataset
{
	int numStudents;
	Student* students; 
};

struct Rejects
{
	int numRejects;
	int* rejects;
};

struct Mode
{
	int numModes;
	int* modes;
};

struct Statistics
{
	int   minimum;
	float average;
	int   maximum;
	float popStdDev;
	float smplStdDev;
	Mode  mode;
	int   histogram[10];
};

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
//
void selection(int dataset[],const int size,int start);

int readCSV(const char filename[],const int minAcceptableID, const int maxAcceptableID,Dataset& data, Rejects& rejects);

int computeStatistics(Dataset& data, Statistics& stats);

int writeCSV(const char filename[], const Statistics& stats);

bool sort(int dataset[], const int size);


//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS
//

void minimum(Dataset data, Statistics &stats) 
{
	float min = 3.402823e+38;
	for( int i=0 ; i < data.numStudents ; i++)
	{
		if( (data.students[i]).grade < min )
		{
           min = (data.students[i]).grade;
		}
		stats.minimum = min; 
	}
    
}

void average(Dataset data, Statistics &stats) 
{
	float sum, avg;
	sum = 0;
	
	for( int i=0 ; i < data.numStudents ; ++i)
	{
        sum += (data.students[i]).grade; 
    }
	// cout << sum << " <- SUM" << endl;
	avg = sum/(data.numStudents);
	//cout << s << " <- THE GREAT 's' " << endl;
	stats.average =  avg;
}

void maximum(Dataset data, Statistics &stats) 
{
	float max = -3.402823e+38;
	
	for( int i=0 ; i < data.numStudents ; i++)
	{
        if( (data.students[i]).grade > max )
		{
           max = (data.students[i]).grade ;
		}
    }
	
	stats.maximum = max;
}

void popStdDev(Dataset data, Statistics &stats) 
{

	float avg = stats.average ;
	float temp = 0;
	float avg1 = 0;
	
	for ( int i=0 ; i < data.numStudents ; i++)
	{
		temp = (data.students[i]).grade - avg;
		avg1 += pow(temp,2);
	}
	
	
	stats.popStdDev =  sqrt(avg1/(data.numStudents));
}

void smplStdDev(Dataset data, Statistics &stats) 
{
    float avg = stats.average;	
	float temp = 0;
	float avg1 = 0;
	
	for ( int i=0 ; i < data.numStudents ; i++)
	{
		temp = (data.students[i]).grade - avg;
		avg1 += pow(temp,2);
	}
	
	stats.smplStdDev = sqrt(avg1/((data.numStudents)-1));

}



int StoInt (const char var[],int maxChar ,int &Grade , int &StudentId , int &commacounter , bool &spacecheck)
{ 
  int value = 0;
  int i = 0;
  int counter = 0;
   //cout << "poekonda  = " << var[0] << endl;
  for(i = 0 ; var[i] != 0 ; i ++) 
  {
    if(var[0] == 0 || var[0] == ' ')
    {
     spacecheck = false;    
    // var[0] = 0;
    }
    else
    {
    if(var[i] == ',')
    {
      StudentId = value;
      value = 0;
      counter++;
    } 
    else if(var[i] == ' ')
    {
       spacecheck = false;
      continue;
     
    }
    else if(var[i] >= 48 && var[i] <= 57)
    {   
      value *= 10;
      value += var[i] - 48;
    }
   // else if(var[i] <= 48 && var[i] >= 57)
    //{   
     //  spacecheck = false;
    //}
  }  
  commacounter = counter;
   Grade = value;
   return 0;
}
}

void selection(int dataset[] , const int size , int start)
{

  if(start == size)
   return;
     
  int minIndex = start;
    
  for (  int index = start + 1 ; index < size; index++ )
  {
    if ( dataset[index] < dataset[minIndex] )
      minIndex = index;
  }
  
  int temp = dataset[start] ;
  dataset[start] = dataset[minIndex];
  dataset[minIndex] = temp;

  selection(dataset,size,start+1);

}

bool sort(int dataset[], const int size)
{
  int start = 0;
  selection(dataset , size , start);

  for (int i = 0; i < size - 1; i ++) {
    if (dataset[i] > dataset[i + 1])
      return false;
  }

  return 1;
}


int mode(Dataset data, Statistics &stats, Mode &modes)
{
   int m = 0;
  int a[data.numStudents];

  for(int i = 0 ; i < data.numStudents ; ++i)
      a[i] = (data.students[i]).grade;

    sort(a ,(data.numStudents));

  //for(int i = 0 ; i < s ; ++i)
   // cout << a[i] << " , ";
  //cout << "\n";


  if(data.numStudents <= 0)
    return -1;

  int max =  -2147483648;
  int count = 0;
  int temp = 0;
  int *tmp;

  for(int i = 0 ; i<data.numStudents ; ++i)
  {

    for(int j = 0; j< data.numStudents ; ++j)
    {
      if(a[i] == a[j])
        ++count;
    }
    if( count > max)
      max = count;

    count  = 0;
 }

  int k = 0;

 for(int i = 0 ; i<data.numStudents ; ++i)
 {
 //	cout << i << " i ni ban " << endl;
   for(int j = 0; j< data.numStudents; ++j)
   {
  // 	cout << j << " <---j desu" << endl;
      if(a[i] == a[j])
      ++count ;
   }
   if( count == max)
   {
    if(k == 0 || modes.modes[k-1] != a[i])
    {
      
      	tmp = modes.modes;
      	m ++;
      	modes.modes = new int[m];
      	for (int i = 0; i < m - 1; i++)
      		modes.modes[i] = tmp[i];
      	modes.modes[m - 1] = a[i];
      	modes.numModes = m;
      	delete [] tmp; 
        ++k;
 //       cout << modes.modes[m - 1] << " <- これが mode　です!" << endl;
 //       cout << k << "<---- k desu" << endl;
    }
  }
 // cout << i << "<-- i desu " << endl;
    count = 0;
  }
  
 }

int readCSV(const char filename[],const int minAcceptableID, const int maxAcceptableID, Dataset& data, Rejects& rejects)
{// cout << "I am Batmann" <<endl;
   if(minAcceptableID > maxAcceptableID)
    return -1;
  //if(histogram == NULL)
   // return -1;
    char filename1[100] ;
  char STAT[10] = {'.','s','t','a','t',0};
  char CSV[10] = {'c' , 's' , 'v' , 0};
  int k = 0;
  bool check = true;
  int count = 0;
  int j = 0;
     for(int i = 0 ; filename[i] != '\0' ; ++i)
  {
    if(filename[i-1] == '.')
    {
          for(int j = i ; filename[j] != '\0' ; ++j)
      {
        ++count;
      }
      break;
    }

  }
  if(count > 3)
  {
    return -1;
  }
  for(int i = 0 ; filename[i] != '\0' ; ++i)
  {
    if(filename[i-1] == '.')
    {
          if(!(filename[i] == CSV[k]))
          {
            check = false;
            k++;
          }
    }

  }
  k = 0;
  j = 0;
  if(check == false) 
  {
    return -1;
  }
  for(int i = 0 ; filename[i] != '\0' ; ++i )
  {
    if(filename[i] == '.')
    { 
      for( j = i ; k < 5 ; ++j ,++k)
      {
        //cout << STAT << " poeko" << endl;
        filename1[j] = STAT[k];
      }
        filename1[j] = 0;
          break;
    }
       filename1[i] = filename[i];
    if(filename[i+1] == '\0')
    {  
      //cout << " pokemon " << filename1 << endl;
      //   filename1[i+1] = filename[i];
      for( j = i+1 ; k < 5 ; ++j , k++)
      {
        //cout << filename1 << " poeko" << endl;
        filename1[j] = STAT[k];
      }
      filename1[j] = 0;

          break;
    }
        filename1[i] = filename[i];
  }
cout << filename1;
  ifstream fin(filename); 

   if(!fin.is_open())
   {
    return -1;
   }
int  s = 0;int  r = 0;
   int commacounter = 0;
   bool Check = true;
   bool CheckComma = true;
   int counter = 0;
   int lineCounter = 0;
    j = 0;
   int maxChar = 100;
   char var[maxChar];
   count = 0;
   int StudentId = 0;
   int Grade = 0;
   bool Done  = true;
   int Deli = 0;
   bool spacecheck = true;;
   
   Student *tmp;
   int *temp;


  while(!fin.eof())
  {  
    fin.getline(var,maxChar);
    lineCounter++;
    spacecheck = true;
    commacounter = 0;
    //cout <<  endl;
    StoInt(var,maxChar,Grade,StudentId,commacounter,spacecheck);
    //cout <<  StudentId << "      <- Student ID" << endl; 
    //cout << Grade << "      <- Grade" << endl;
    //cout << spacecheck << "      <- space check" << endl;
    //cout << commacounter << "     <- comma counting shit" << endl;
    //cout << var << "       <- the bloody line" << endl;
    //for(int l = 0; var[l] != '\0' ; l++)
    //{
      //cout << var[l];

    //}
    //cout << endl;
    //cout << endl;
   if( var[0] != 0 )
   {
       // cout << var[1] << endl;
      //cout << var << endl;
      if(StudentId < minAcceptableID || StudentId > maxAcceptableID || Grade > 100 || Grade < 0 || Check == false || commacounter > 1 || spacecheck == false)
      { 
     //	cout << "thenga" << endl;

        temp = rejects.rejects;
        r ++;
        	rejects.rejects = new int[r];
        	for ( int i = 0; i < r - 1; i ++)
        		rejects.rejects[i] = temp[i];
        	rejects.rejects[r - 1] = lineCounter;
        	rejects.numRejects = r;
        	delete [] temp;  
             
       counter++;
         Deli = -1;
         cout << rejects.numRejects << endl;

       }

      if(Deli == 0)
      {


        tmp = data.students;
        s ++;
        data.students = new Student[s];

        for (int i = 0; i < s - 1; i ++)
        	data.students[i] = tmp[i];

        data.students[s - 1].grade = Grade;
        data.students[s - 1].studentID = StudentId;
        data.numStudents = s;
        delete tmp;
    //    cout << data.students[s - 1].grade << " <- Grade inside the BS" << endl; 

      }
      Deli = 0;
      j = 0;
      CheckComma = true; 
   }
}

  fin.close();
  if(counter > 10)
    return -1;
 return rejects.numRejects;
}

int computeStatistics(Dataset& data, Statistics& stats)
{ 
	Mode modes = {0};
  for(int i = 0 ; i < data.numStudents ; i++)
     stats.histogram[i] = 0;
	for(int i = 0 ; i < data.numStudents ; i++)
	   stats.histogram[(data.students[i].grade)/10] = stats.histogram[(data.students[i].grade)/10] + 1;
    minimum(data, stats);  
    average(data, stats);
    maximum(data, stats); 
    popStdDev(data, stats);
    smplStdDev(data, stats); 
  //  cout << " potato " << endl;
    mode(data, stats, modes);
    stats.mode.modes = modes.modes;
    stats.mode.numModes = modes.numModes;

  //  cout << stats.mode.modes  << " <--- これ　も　もど　ですよ！！"<< endl;
    return 0;
}



int writeCSV(const char filename[], const Statistics& stats)
{
	ofstream fout;
	char filename1[100] ;
	char STAT[10] = {'.','s','t','a','t',0};
	char CSV[10] = {'c' , 's' , 'v' , 0};
	int k = 0;
	bool check = true;
	int count = 0;
	int j = 0;

    for(int i = 0 ; filename[i] != '\0' ; ++i)
	{
		if(filename[i-1] == '.')
		{
          for(int j = i ; filename[j] != '\0' ; ++j)
		  {
		  	++count;
		  }
		  break;
		}

	}
	if(count > 3)
	{
		return -1;
	}
	for(int i = 0 ; filename[i] != '\0' ; ++i)
	{
		if(filename[i-1] == '.')
		{
          if(!(filename[i] == CSV[k]))
          {
          	check = false;
          	k++;
          }
		}

	}
  k = 0;
  j = 0;
  if(check == false)
  {
    return -1;
  }
	for(int i = 0 ; filename[i] != '\0' ; ++i )
	{
		if(filename[i] == '.')
		{ 
		  for( j = i ; k < 5 ; ++j ,++k)
		  {
		  	//cout << STAT << " poeko" << endl;
		  	filename1[j] = STAT[k];
		  }
		    filename1[j] = 0;
          break;
		}
		   filename1[i] = filename[i];
		if(filename[i+1] == '\0')
		{  
			//cout << " pokemon " << filename1 << endl;
			// 	 filename1[i+1] = filename[i];
			for( j = i+1 ; k < 5 ; ++j , k++)
		  {
		  	//cout << filename1 << " poeko" << endl;
		  	filename1[j] = STAT[k];
		  }
		  filename1[j] = 0;

          break;
		}
        filename1[i] = filename[i];
	}

	//cout <<  filename1 << endl;
	fout.open(filename1);
	if(!fout.is_open())
		return -1;
	
  fout << "Minimum: " << stats.minimum << std::endl;
  fout << "Average: " << stats.average << std::endl ;
	fout << "Maximum: " << stats.maximum << std::endl;
	fout << "Population Standard Deviation: " << stats.popStdDev << std::endl;
	fout << "Sample Standard Deviation: " << stats.smplStdDev << std::endl;
	fout <<  "Modes: "; 
	for (unsigned char i = 0; i < stats.mode.numModes; i++)
	{  if(i+1 == stats.mode.numModes)
		{
			fout << stats.mode.modes[i];
			break;
		}
		fout  << stats.mode.modes[i] << ", ";
		
	}
    fout << std::endl;
	fout<<"Histogram:" << std::endl;

	for (unsigned char i = 0; i < 10; i++)
	{
		if(i+1 == 10)
	    {
	    	 fout << "[" << (i*10) << "-" << ((((i+1)*10) - 1) + i/9) << "]: " << stats.histogram[i];
	    	 break;
	    }
	    fout << "[" << (i*10) << "-" << ((((i+1)*10) - 1) + i/9) << "]: " << stats.histogram[i] << std::endl;
	    
	}
	fout.close();
	return 0;


}
//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
  	
	// Some test driver code here ....
	int minAcceptableID = 0;
	int maxAcceptableID = 200000000;

	Dataset data = {0};
	Rejects rejects = {0};
	Statistics stats = {0};

	std::cout << std::endl << "Implement some more appropriate tests in main()" << std::endl << std::endl;

	if(readCSV(argv[1], minAcceptableID, maxAcceptableID, data, rejects) < 0)
	{
		std::cout << ".csv file could not be read" << std::endl;
	}

	if (computeStatistics(data, stats) < 0)
	{
		std::cout << "Stats could not be computed" << std::endl;
	}

	if (writeCSV(argv[1], stats) < 0)
	{
		std::cout << ".stat file could not be written" << std::endl;
	}
   // cout << " monkey" << endl;
	std::cout << "Average: " << stats.average << std::endl;
	std::cout << "Minimum: " << stats.minimum << std::endl;
	std::cout << "Maximum: " << stats.maximum << std::endl;
	std::cout << "Population standard deviation: " << stats.popStdDev << std::endl;
	std::cout << "Sample standard deviation: " << stats.smplStdDev << std::endl;
	
	
	for (unsigned char i = 0; i < stats.mode.numModes; i++)
	{
		std::cout << "Mode: " << stats.mode.modes[i] << std::endl;
	}

	for (unsigned char i = 0; i < 10; i++)
	{
		std::cout << "Histogram bin [" << (i*10) << ", " << ((((i+1)*10) - 1) + i/9) << "]: " << stats.histogram[i] << std::endl;
	}
	

	return 0;
}

#endif
