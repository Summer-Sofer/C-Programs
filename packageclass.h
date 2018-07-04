#ifndef _PACKAGECLASS_H_
#define _PACKAGECLASS_H_

using namespace std;

class Package
{
  protected:
    string senderName, senderAddress, senderCity, receiverName, receiverAddress, receiverCity;
    int senderZip, receiverZip;
    float weightOunces, costPerOunce;

  public:
    Package() {weightOunces = costPerOunce = 0; }
    Package(float w, float c) {setWeightOunces(w); setCostPerOunce(c); }
    // Package(const Package& rhs) {weightOunces = rhs.weightOunces; costPerOunce = rhs.costPerOunce; }
    float getWeightOunces() const { return weightOunces; }
    float getCostPerOunce() const { return costPerOunce; }
    double calculateCost() const { return weightOunces * costPerOunce; }

    void setCostPerOunce(float c);
    void setWeightOunces(float w);
    void displayPackageCost(Package p);

    // friend ostream& operator<<(ostream& os, const Package& package1);

    ~Package() {};
};

class TwoDayPackage: public Package
{
  protected:
    float flatFee;

  public:
    TwoDayPackage(): Package() {flatFee = 0;}
    TwoDayPackage(float w, float c, float f): Package(w, c) {setFlatFee(f); }
    // TwoDayPackage(const TwoDayPackage& rhs): Package(rhs) {flatFee = rhs.flatFee; }

    void setFlatFee(float f);
    double getFlatFee() const {return flatFee; }
    double calculateCost() const {return Package::calculateCost() + flatFee; }
    void displayPackageCost(TwoDayPackage t);

    // friend ostream& operator<<(ostream& os, const TwoDayPackage& package2);

    ~TwoDayPackage() {};
};

class OvernightPackage: public Package
{
  protected:
    float feePerOunce;

  public:
    OvernightPackage(): Package() {feePerOunce = 0; }
    OvernightPackage(float w, float c, float o): Package(w, c) {setFeePerOunce(o); }
    // OvernightPackage(const OvernightPackage& rhs): Package(rhs) {feePerOunce = rhs.feePerOunce; }

    void setFeePerOunce(float o);
    double getFeePerOunce() const {return feePerOunce; }
    double calculateFee() const {return feePerOunce * weightOunces; }
    double calculateCost() const {return (feePerOunce + costPerOunce) * weightOunces; }
    void displayPackageCost(OvernightPackage n);

    // friend ostream& operator<<(ostream& os, const OvernightPackage& package3);

    ~OvernightPackage() {};
};
