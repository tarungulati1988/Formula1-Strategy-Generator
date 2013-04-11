package com.f1strategy;

import static java.lang.System.*;
import java.util.HashMap;
import java.util.Scanner;

public class F1StrategyGeneratorInput {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//--------Variable declarations---------
		int lapNumber, gridPosition, tempTireSetsUsed;
		int freshSetOptions = 3, frshSetPrimes = 3;
		String driverName, tempTireType, q3TimeSetOnTire;
		boolean q1, q2, q3;
		Scanner scanner = new Scanner(in);
		HashMap<String, Integer> q1TireMap = new HashMap<String, Integer>();
		HashMap<String, Integer> q2TireMap = new HashMap<String, Integer>();
		HashMap<String, Integer> q3TireMap = new HashMap<String, Integer>();
		
		//--------Output statements to get input from user--------
		out.println("Driver: ");
		driverName = scanner.nextLine();
		out.println("Lap number: ");
		lapNumber = scanner.nextInt();
		out.println("Grid Position: ");
		gridPosition = scanner.nextInt();
		out.println("Time set in Q1(true or false): ");
		q1 = scanner.nextBoolean();
		
		if(q1 == true){
			out.println("Type of tire used(Q1): ");
			tempTireType = scanner.next();
			out.println("Number of sets used(Q1): ");
			tempTireSetsUsed = scanner.nextInt();
			q1TireMap.put(tempTireType, tempTireSetsUsed);
			out.println("Time set in Q2(true or false): ");
			q2 = scanner.nextBoolean();
			
			if(q2 == true){
				out.println("Type of tire used(Q2): ");
				tempTireType = scanner.next();
				out.println("Number of sets used(Q2): ");
				tempTireSetsUsed = scanner.nextInt();
				q2TireMap.put(tempTireType, tempTireSetsUsed);
				out.println("Time set in Q3(true or false): ");
				q3 = scanner.nextBoolean();
				
				if(q3 == true){
					out.println("Type of tire used(Q3): ");
					tempTireType = scanner.next();
					out.println("Number of sets used(Q3): ");
					tempTireSetsUsed = scanner.nextInt();
					out.println("Qualifying time set on which type of tire: ");
					q3TimeSetOnTire = scanner.next();
					q3TireMap.put(tempTireType, tempTireSetsUsed);
				}
				else{
					q3 = false;
				}
			}
			else{
				q3 = false;
				q2 = false;
			}
		}
		else{
			q2 = false;
			q3 = false;
		}
		
		
	}

}
