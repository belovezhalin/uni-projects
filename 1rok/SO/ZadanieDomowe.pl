#!/usr/bin/perl -w                                                                  #Anhelina Belavezha gr 3

binmode(STDIN, ":encoding(utf8)");                                                  #ustawienie kodowania znakow na UTF-8
binmode(STDOUT, ":encoding(utf8)");                                                 #(ASCII moze nie wystarczyc)
 
my $html = '';                                                                      #wczytanie pliku z argumentu lub z wejscia
if (-t STDIN) {
    if ($ARGV[0]) {
        open(my $fh, '<', $ARGV[0]) or die "nie mozna otworzyc pliku $ARGV[0]: $!";
        while (my $line = <$fh>) {
            $html .= $line;}
        close($fh);} 
    else {
        die "nie znaleziono pliku\n";}} 
else {
    while (my $line = <STDIN>) {
        $html .= $line;}}

my @tables;                                                                         #znalezienie tabel
while ($html =~ /<table.*?>.*?<\/table>/isg) {
    push @tables, $&;}

for my $table (@tables) {
    my @rows;
    while ($table =~ /<tr.*?>.*?<\/tr>/isg) {
        push @rows, $&;}

    my $num_rows = scalar @rows;

    $rows[0] =~ s/<\/tr>/<th>Suma<\/th><\/tr>/i;

    for (my $i = 1; $i < $num_rows; $i++) {
        my @cells;
        while ($rows[$i] =~ /<td.*?>\s*([\d\s]+?)\s*<\/td>/isg) {
            push @cells, $1;}

        my $sum = 0;
        for my $cell (@cells) {
            $cell =~ s/\s+//g;                                                   #usuniecie spacji
            $sum += $cell if $cell =~ /^\d+$/;}
        $rows[$i] =~ s/<\/tr>/<td>$sum<\/td><\/tr>/i;}

    my $new_table = join('', @rows);                                             #zlozenie wierszy do jednej tabeli

    $html =~ s/\Q$table/$new_table/;}                                            #zamiana tabeli

print $html;