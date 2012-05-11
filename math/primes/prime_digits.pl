#!/usr/bin/perl

print "This program generates the prime factorization of the numbers 2 through N, where N is input by the user.\nPlease enter N:";
chomp($N=<STDIN>);
$digits=int((log $N)/(log 10)) + 1;
@primes=@{sieve($N)};
printf "%".$digits."s  ".("%".$digits."d ")x@primes."\n", 'n', @primes;
for($n = 2; $n <= $N; $n++)
{
    $factors=factor($n,\@primes);
    printf "%".$digits."d: ".("%".$digits."d ")x@primes."\n", $n, @$factors;
}

sub factor
{
    my $number = shift;
    my @primes = @{ shift @_};
    my $remainder = $number;
    my @factors = ();
    for($i = 0; $i <= $#primes; $i++)
    {
        $factors[$i]=0;
        while($remainder % $primes[$i] == 0)
        {
            $remainder /= $primes[$i];
            $factors[$i]++;
        }
    }
    return \@factors;
}

sub sieve
{
    my $final = shift;
    my @iscomposite; #A mark of 1 means composite (default state is 0, meaning prime)
    $iscomposite[0]=1; 
    $iscomposite[1]=1;
    for($n = 2; $n<= $final; $n++)
    {
        next if $iscomposite[$n]==1;
        for($i = 2; $i*$n<=$final; $i++)
        {
            $iscomposite[$i*$n]=1;
        }
    }
    my @primes;
    for($n = 2; $n<= $final; $n++)
    {
        push @primes,$n unless $iscomposite[$n];
    }
    return \@primes;
}
