//
//  main.cpp
//  itch4Parser
//
//  Created by Dylan Hurd on 11/3/13.
//  Copyright (c) 2013 Dylan Hurd. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Message.cpp"

using namespace std;


int main(int argc, const char * argv[])
{
  std::ios_base::sync_with_stdio(false);
 
  if(argc != 3) {
    cerr << "Incorrect number of args\n";
    cerr << "Correct usage: ./itch4parser [input file] [output file]";
    return 1;
  }

  // Opening input file in binary mode
  ifstream input(argv[1], ios::in );
  if(!input.is_open()){
    cerr << "Error opening input file";
    return 1;
  }
  
  ofstream output(argv[2], ios::out | ios::trunc);
  if(!output.is_open()){
    cerr << "Error opening output file";
    return 1;
  }
  
  char c;
  TimeStamp ts;
  
  while(input.good()){
    input >> c;
    //determine message type, add to vector
    if(c == 'T') {
      input >> ts;
    }
    else if(c == 'S'){
      Message o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'R'){
      StockDirectory o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'H'){
      StockTradingAction o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'Y'){
      ShortSalePriceTest o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'L'){
      MarketParticipantPosition o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'A'){
      AddOrder o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'F'){
      AddMPIDOrder o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'E'){
      ExecutedOrder o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'C'){
      ExecutedPriceOrder o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'X'){
      CancelOrder o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'D'){
      DeleteOrder o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'U'){
      ReplaceOrder o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'P'){
      TradeMessage o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'Q'){
      CrossTradeMessage o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'B'){
      BrokenTrade o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'I'){
      NetOrderImbalance o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else if(c == 'N'){
      RetailPriceImprovement o;
      o.ts = ts;
      input >> o;
      output << o;
    }
    else {
      //cerr << "Error in reading input\n";
      continue;
    }
  }
 
  cerr << "Finished reading\n";  
  return 0;
}

