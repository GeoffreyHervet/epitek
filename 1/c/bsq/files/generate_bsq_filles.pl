#!/usr/pkg/bin/perl -w
## generate_bsq_filles.pl for bsq in /home/hervet_g//work/projets/c
## 
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
## 
## Started on  Mon Nov  1 11:39:51 2010 geoffrey hervet
## Last update Mon Nov  1 11:44:36 2010 geoffrey hervet
##


if ((scalar @ARGV) <= 1)
{
    print "program size density\n";
    exit;
}

my $size = $ARGV[0];
my $density = $ARGV[1];
my $i = 0;
my $j = 0;

print $size . "\n";

while ($i < $size)
{
    $j = 0;
    while ($j < $size)
    {
        if (int(rand($size)*2) < $density)
        {
            print 'o';
        }
        else
        {
            print '.';
        }
        $j++;
    }
    print "\n";
    $i++;
}
