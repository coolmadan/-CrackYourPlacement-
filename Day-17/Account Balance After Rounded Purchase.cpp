class Solution {
public:
    int roundToNearestMultipleOf10(int number) {
    return round(number / 10.0) * 10;
}
    int accountBalanceAfterPurchase(int purchaseAmount) {
        purchaseAmount=roundToNearestMultipleOf10(purchaseAmount);
        return abs(100-purchaseAmount);
    }
};
