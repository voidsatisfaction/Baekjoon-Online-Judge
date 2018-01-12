chomp (my $T = <STDIN>);
for (my $i=0; $i < $T; $i++) {
  chomp (my $input = <STDIN>);
  my @all_words = split(/ /, $input);
  my %all_words = ();
  foreach my $word (@all_words) {
    $all_words{$word} = 1;
  }

  chomp ($input = <STDIN>);
  while ($input ne 'what does the fox say?') {
    my @not_fox_words = split(/ /, $input);
    $all_words{$not_fox_words[2]} = 0;
    chomp ($input = <STDIN>);
  }

  my @fox_words = ();
  foreach my $word (@all_words) {
    if ($all_words{$word}) {
      push @fox_words, $word;
    }
  }

  print join ' ', @fox_words, "\n";
}