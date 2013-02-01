#!/usr/bin/env php
<?php

$repos = file('repos');
if (0)
  foreach ($repos as &$name)
  {
    $name = trim($name);
    $cmd = 'svn co svn+ssh://kscm@koala-rendus/' . $name;
    echo `$cmd`;
    echo '###########', PHP_EOL;
  }
if (1)
{
  foreach ($repos as &$name)
  {
    $name = trim($name);
    echo `cd $name && svn log > svn.log && cd -`;
    echo '###########', PHP_EOL;
  }
}
