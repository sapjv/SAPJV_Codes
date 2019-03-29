import java.util.*;             // for using Scanner class

// Creating Student class for Student record and Student Object
class Student           
{ 
	public String name; 
	public double cgpa; 
	public int token;
	public Student(String name, double cgpa, int token) 
	{ 
		this.name = name; 
		this.cgpa = cgpa; 
		this.token = token;
	} 
	
	// Returning the Student Name
	public String getName() 
	{ 
		return name; 
	} 
} 


class StudentComparator implements Comparator<Student>
{ 
    // Overriding compare() method of Comparator class as per given order in the problem statement 
	public int compare(Student s1, Student s2) 
	{ 
	    // if students are having the same CGPA , then they will be served by name in ascending case-sensitive alphabetical order.
	    if(s1.cgpa == s2.cgpa)
	    {
	        if(((s1.name).compareTo(s2.name))>0)
	        return 1;
	        else if(((s1.name).compareTo(s2.name))<0)
	        return -1;
	        
	        // If students are having the same CGPA and name , then they will be served in ascending token order.
	        else if(((s1.name).compareTo(s2.name))==0)
	        {
	            if(s1.token>s2.token)
	            return 1;
	            else
	            return -1;
	        }
	    }
	    
	    // Student having the highest Cumulative Grade Point Average (CGPA) will be served first.
    	else if (s1.cgpa < s2.cgpa) 
    		return 1; 
    	return -1;  
    } 
} 
public class Solution 
{ 
	public static void main(String[] args)
	{ 
	    // Creating Scanner class Object
		Scanner obj = new Scanner(System.in);
		
		// Taking input of total number of events
		int t = obj.nextInt();
		
		// Creating Priority queue constructor having initial capacity=t and a StudentComparator instance as its parameters
		PriorityQueue<Student> pq = new PriorityQueue<Student>(t, new StudentComparator()); 
		
		// iterating t times
		for(int i=0;i<t;i++)
		{
		    // taking input of user's choice
		    String choice = obj.next();
		    
		    // if user wants to insert the record
		    if(choice.equals("ENTER"))
		    {
    		    String s = obj.next();          // taking input of student name
    		    double gpa = obj.nextDouble();          // taking input of student GPA
    		    int token = obj.nextInt();          // taking input of token
            	Student student = new Student(s,gpa,token);         // Creating each student record for inserting into the priority queue
            	pq.add(student);                        // inserting each student record in priority queue
		    }
		    
		    // if user wants to serve
		    else if(choice.equals("SERVED"))
		    {
		        pq.poll().getName();
		    }
        	
		}
		
		// if every student in the queue has been served, then printing EMPTY.
		if(pq.isEmpty())
		System.out.println("EMPTY");
		else
		{
    		// Printing the names (based on the criteria) of the students who are not served at all after executing all events
    		while (!pq.isEmpty()) 
    		    System.out.println(pq.poll().getName()); 
		}
	} 
} 
