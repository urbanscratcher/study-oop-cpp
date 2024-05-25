class MerkelMain
{
public:
  MerkelMain();
  /** Call this to start the sim */
  void init();

private:
  void printMenu();
  void printHelp();
  void printMarketStats();
  void enterOffer();
  void enterBid();
  void printWallet();
  void gotoNextTimeframe();
  int getUserOption();
  void processUserOption(int userOption);
  int main();
};