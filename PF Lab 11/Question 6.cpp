#include <stdio.h>
#include <string.h>

struct Invoice {
    char partNumber[20];
    char partDescription[50];
    int quantity;
    float pricePerItem;
};

float calculateInvoiceAmount(struct Invoice *invoice) {
    if (invoice->quantity <= 0) {
        invoice->quantity = 0;
    }
    if (invoice->pricePerItem <= 0) {
        invoice->pricePerItem = 0;
    }
    return invoice->quantity * invoice->pricePerItem;
}

void printFormattedAmount(float amount) {
    printf("PKR %.2f\n", amount);
}

void displayInvoiceDetails(struct Invoice invoice) {
    printf("Part Number: %s\n", invoice.partNumber);
    printf("Part Description: %s\n", invoice.partDescription);
    printf("Quantity: %d\n", invoice.quantity);
    printf("Price per Item: ");
    printFormattedAmount(invoice.pricePerItem);
    float invoiceAmount = calculateInvoiceAmount(&invoice);
    printf("Invoice Amount: ");
    printFormattedAmount(invoiceAmount);
}

int main() {
    struct Invoice invoice1;
    strcpy(invoice1.partNumber, "A12345");
    strcpy(invoice1.partDescription, "Hammer");
    invoice1.quantity = 10;
    invoice1.pricePerItem = 15.50;

    printf("Invoice Details (My Invoice):\n");
    displayInvoiceDetails(invoice1);

    struct Invoice invoice2;
    strcpy(invoice2.partNumber, "B98765");
    strcpy(invoice2.partDescription, "Wrench");
    invoice2.quantity = -5;
    invoice2.pricePerItem = -20.00;

    printf("\nInvoice Details (Your Invoice):\n");
    displayInvoiceDetails(invoice2);

    return 0;
}

