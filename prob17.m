% problem 17
% count all the letters involved in writing out the numbers from 1 to 1000
% one to one thousand

% no's of letters in the basic numbers from 1 to 19
% one   3   eleven    6
% two   3   twelve    6
% three 5   thirteen  8
% four  4   fourteen  8
% five  4   fifteen   7
% six   3   sixteen   7
% seven 5   seventeen 9
% eight 5   eighteen  8
% nine  4   nineteen  8
% ten   5
basic = [3 3 5 4 4 3 5 5 4]; % numbers 1-9
teens = [3 6 6 8 8 7 7 9 8 8]; % numbers 10-19
% twenty  6
% thirty  6
% forty   5
% fifty   5
% sixty   5
% seventy 7
% eighty  6
% ninety  6
tens = [6 6 5 5 5 7 6 6];

% first lets figure out the characters from 1 to 99
% the basic numbers occur 9 times (one, twenty one, ... ,ninety one)
% the teens occur once
% the tens occur ten times (twenty... twenty nine)
oneto99 = 9*sum(basic) +sum(teens) + 10*sum(tens);

% now the final calculation
% the basic numbers occur 100 times
% (one hundred, one hundred and one,.. one hundred and ninety nine)
% the word hundred (7) appears 899 times (100-999)
% the word and (3) appears for every word hundred except for (100,200,..)
% so thats 899-9 = 890
% oneto99 appears ten times
oneto999 = 100*sum(basic) + 7*899 + 3*890 + 10*oneto99;

% plus the number one (3) thousand (8)
ans = oneto999 + 11

