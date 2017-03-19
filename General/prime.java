/**
Finds all the prime numbers before a positive integer, which is input from the user.
Based on the Sieve of Eratosthenes concept of finding prime numbers
**/
public class PrimeDP {

 int primes[];
 public boolean isPrime(int x) {
  if(x<2) return false;
  for(int k=0;k < primes.length && primes[k]*primes[k] <= x;k++)
   if(x%primes[k]==0) return false;
  return true;
 }

 public int getPrime(int index) {
  return primes[index];
 }

 public PrimeDP(int n) {
  primes = new int[n];
  primes[0] = 2;
  primes[1] = 3;
  for(int k=2,i=6;k < n;i+=6) {
   if(isPrime(i-1)) primes[k++]=i-1;
   if(k < n && isPrime(i+1))
   primes[k++]=i+1;
  }
 }

 public static void main(String []args) {
  long a = System.currentTimeMillis();
  int n = 200000;
  PrimeDP p = new PrimeDP(n);
  long b = System.currentTimeMillis();

  System.out.println("time = " + (b-a) + " ms.");
 }
}
