sub is_prime {
  my ($n) = @_;

  if ($n == 1) { return 0; }

  for (my $i = 2; $i * $i <= $n; $i++) {
    if ($n % $i == 0) {
      return 0;
    }
  }
  return 1;
}

my $n = <STDIN>;
my $input = <STDIN>;
my @nums = split(/ /, $input);

my @ans = grep { is_prime($_) } @nums;

my $length = @ans;

print $length;
print "\n";