my $input = <STDIN>;
my @input = split(/ /, $input);
my ($A, $B, $C) = @input;

my $exp1 = ($A + $B) % $C;
my $exp2 = ($A % $C + $B % $C) % $C;
my $exp3 = ($A * $B) % $C;
my $exp4 = (($A % $C) * ($B % $C)) % $C;

print $exp1;
print "\n";
print $exp2;
print "\n";
print $exp3;
print "\n";
print $exp4;
print "\n";