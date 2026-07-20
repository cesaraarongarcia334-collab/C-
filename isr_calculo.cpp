/*
 * ACTIVIDAD 2 - FLUJO DE CONTROL PARTE 1
 * Logica de Programacion
 * Prof. Gamalier Reyes del Carmen
 *
 * Programa que lee el sueldo bruto mensual de un empleado, calcula el
 * Impuesto Sobre la Renta (ISR) segun la escala vigente de la DGII para
 * el año fiscal 2026 (Republica Dominicana), y muestra el sueldo junto
 * con el monto de ISR a descontar (o N/A si no aplica).
 *
 * Fuente de la escala: Codigo Tributario (Ley 11-92, Art. 296), escala
 * heredada vigente durante 2026 (aun sin el ajuste de la Ley 30-26, que
 * entra en vigencia en 2027).
 *
 * Procedimiento oficial:
 *   1) Se resta al salario bruto el aporte del empleado a la Seguridad
 *      Social (TSS = AFP 2.87% + SFS 3.04% = 5.91%) para obtener el
 *      neto gravable.
 *   2) Se compara el neto gravable mensual contra la escala mensual del
 *      ISR (montos anuales de la DGII divididos entre 12) y se aplica
 *      la tasa progresiva correspondiente.
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double sueldoBruto;
    const double TASA_TSS = 0.0591; // AFP 2.87% + SFS 3.04%

    // Escala mensual ISR 2026 (DGII), derivada de la escala anual:
    // Exento hasta 416,220.00 anual -> 34,685.00 mensual
    const double LIMITE1 = 34685.00;   // Exento
    const double LIMITE2 = 52027.42;   // 15% sobre excedente de LIMITE1
    const double LIMITE3 = 72260.25;   // RD$2,601.33 + 20% sobre excedente de LIMITE2
    const double CUOTA_FIJA2 = 2601.33;
    const double CUOTA_FIJA3 = 6648.00; // + 25% sobre excedente de LIMITE3

    cout << "===== CALCULO DE ISR - EMPLEADO (DGII 2026, Rep. Dominicana) =====" << endl;
    cout << "Ingrese el sueldo bruto mensual del empleado (RD$): ";
    cin >> sueldoBruto;

    // Validacion basica de entrada
    if (sueldoBruto < 0) {
        cout << "Error: el sueldo no puede ser un valor negativo." << endl;
        return 1;
    }

    // Paso 1: obtener el neto gravable (bruto menos TSS del empleado)
    double descuentoTSS = sueldoBruto * TASA_TSS;
    double netoGravable = sueldoBruto - descuentoTSS;

    // Paso 2: aplicar la escala progresiva del ISR
    double isr = 0.0;

    if (netoGravable <= LIMITE1) {
        isr = 0.0;
    } else if (netoGravable <= LIMITE2) {
        isr = (netoGravable - LIMITE1) * 0.15;
    } else if (netoGravable <= LIMITE3) {
        isr = CUOTA_FIJA2 + (netoGravable - LIMITE2) * 0.20;
    } else {
        isr = CUOTA_FIJA3 + (netoGravable - LIMITE3) * 0.25;
    }

    cout << fixed << setprecision(2);
    cout << "\n--------------------------------------------------" << endl;
    cout << "Sueldo bruto mensual:     RD$ " << sueldoBruto << endl;
    cout << "Descuento TSS (5.91%):    RD$ " << descuentoTSS << endl;
    cout << "Neto gravable:            RD$ " << netoGravable << endl;

    if (isr == 0.0) {
        cout << "ISR a descontar:          N/A (no aplica / exento)" << endl;
    } else {
        cout << "ISR a descontar:          RD$ " << isr << endl;
    }
    cout << "--------------------------------------------------" << endl;

    return 0;
}
