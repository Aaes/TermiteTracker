// cm.cs
using System;
using System.Runtime.InteropServices;

public class MainClass 
{
   [DllImport("Cmdll.dll", EntryPoint="?SampleMethod@@YAHH@Z")]
   public static extern int SampleMethod(int x);

   static void Main() 
   {
      Console.WriteLine("SampleMethod() returns {0}.", SampleMethod(5));
      Console.WriteLine("SampleMethod() returns {0}.", SampleMethod(6));
	  
	  Console.WriteLine("TEST");
	  
	  Console.ReadLine();
   }
}