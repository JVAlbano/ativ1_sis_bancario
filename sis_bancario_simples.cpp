// Atividade 1 de LP1
// Aluno: João Victor Albano do Amaral Silva
// Matrícula: 20220002879


#include <iostream>
#include <string>
using namespace std;

// Classe Cliente
class Cliente {
private:
    string nome;
    string cpf;

public:
    // Construtor do Cliente
    Cliente(string n, string c) {
        nome = n;
        cpf = c;
    }
    
    // Construtor do Cliente sem parâmetros 
    Cliente() {
        nome = "Desconhecido";
        cpf = "000.000.000-00";
    }

    // Getters
    string getNome() const {return nome;}
    string getCpf() const {return cpf;}
};

// Classe ContaBancaria
class ContaBancaria {
private:
    int numero;
    Cliente titular;
    double saldo;

public:
    // Construtor da ContaBancaria
    ContaBancaria(int num, Cliente t, double s = 0.0) {
        numero = num;
        titular = t;
        saldo = s;
    }
    // Construtor da ContaBancaria sem parâmetros
    ContaBancaria() {
        numero = 0;
        titular = Cliente("Desconhecido", "000.000.000-00");
        saldo = 0.0;
    }

    // Método para depositar
    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
        } else {
            cout << "Valor de deposito invalido." << endl;
        }
    }

    // Método para sacar
    void sacar(double valor) {
        if (valor <= saldo && valor > 0) {
            saldo -= valor;
        } else {
            cout << "Saldo insuficiente ou valor invalido para saque." << endl;
        }
    }

    // Transferir para uma conta destino
    void transferir(double valor, ContaBancaria &destino) {
        if (valor <= saldo && valor > 0) {
            saldo -= valor;
            destino.depositar(valor);
            cout << "Transferencia de R$" << valor << " da conta " << numero
                 << " para a conta " << destino.numero << " realizada com sucesso." << endl;
        } else {
            cout << "Saldo insuficiente ou valor invalido para transferencia." << endl;
        }
    }

    // Transferir para duas contas destino
    void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
        double metade = valor / 2.0;
        if (valor <= saldo && valor > 0) {
            saldo -= valor;
            destino1.depositar(metade);
            destino2.depositar(metade);
            cout << "Transferencia de R$" << valor << " da conta " << numero
                 << " para as contas " << destino1.numero << " e " << destino2.numero
                 << " (R$" << metade << " para cada) realizada com sucesso." << endl;
        } else {
            cout << "Saldo insuficiente ou valor invalido para transferencia." << endl;
        }
    }

    // Exibir saldo
    void exibirSaldo() const {
        cout << "Saldo da conta " << numero << " (" << titular.getNome() << "): R$" << saldo << endl;
    }

    // Exibir informações da conta
    void exibirInformacoes() const {
        cout << "-----------------------------------" << endl;
        cout << "Conta: " << numero << endl;
        cout << "Titular: " << titular.getNome() << endl;
        cout << "CPF: " << titular.getCpf() << endl;
        cout << "Saldo: R$" << saldo << endl;
        cout << "-----------------------------------" << endl;
    }
};

// Função principal
int main() {
    // Criação dos clientes
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    // Criação das contas bancárias com saldos iniciais
    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2);
    ContaBancaria conta3(1003, cliente3);

    // Exibe o saldo inicial da conta de Ana
    conta1.exibirSaldo();

    // Ana transfere R$200 para Bruno
    conta1.transferir(200.0, conta2);

    // Ana transfere R$300 divididos entre Bruno e Carla
    conta1.transferir(300.0, conta2, conta3);

    // Exibição dos saldos finais
    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}
