

lli gcd (lli a, lli b) 
{
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}




lli lcm (lli a, lli b) 
{
    return (a / gcd(a, b)) * b;              // or we can write it as  ( (a*b) / gcd(a,b) )
}



