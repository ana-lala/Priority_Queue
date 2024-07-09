/**
 * \file ColaMedieval.hpp
 * \brief Implementaci&oacute;n de una Cola medieval.
 * \author Ana Laura Chenoweth Galaz
 * \date 20/03/2024
 */

#ifndef ColaMedievalMEDIEVAL_HPP_INCLUDED
#define ColaMedievalMEDIEVAL_HPP_INCLUDED

/** \class ColaMedievalMedieval
 *
 * Permite utilizar <b> Colas </b> con la condici&oacuten de que los nobles pasen primero.
 **/

 /**
 *  \class ColaVacia
 *  Excepci&oacute;n lanzada al intentar acceder a los individuos de una Cola vacia.
 **/
    class ColaVacia : public std::exception{
    public:
        virtual const char * what() const throw();
     };
class ColaMedieval
{
public:
    /** \brief Constructor de la clase ColaMedieval.
     *
     */
    ColaMedieval();

    /** \brief Destructor de la clase ColaMedieval.
     *
     */
    ~ColaMedieval();

    /** \brief Constructor de copias de la clase Pila.
     *
     * \param &c ColaMedieval a la cual se le construye la copia.
     *
     */
    ColaMedieval(const ColaMedieval &c);

    /** \brief Sobrecarga del operador de asignaci&oacute;n
     *
     * \param &c ColaMedieval asignada en una nueva ColaMedieval.
     * \return ColaMedieval& ColaMedieval a la cu&aacute;l se le asign&oacute; la ColaMedieval.
     *
     */
    ColaMedieval &operator=(const ColaMedieval &c);

    /** \brief M&eacute;todo para agregar un individuo de la clase social Plebeyo a la ColaMedieval.
     *
     * \param nombre std::string individuo a agregar
     * \return void
     *
     */
    void Agregar(std::string nombre, std::string claseSocial);

    void Eliminar();

    /** \brief M&eacute;todo que regresa el tamaño (el n&uacute;mero de individuos) de la ColaMedieval
     *
     * \return int Tamano de la ColaMedieval.
     *
     */
    int ObtenerTam() const;

    /** \brief M&eacute;todo que regresa el tamaño (el n&uacute;mero de individuos de la clase social Plebeyo) de la ColaMedieval
     *
     * \return int Tamano de los individuos Plebeyos de la ColaMedieval.
     *
     */
    int ObtenerTamPlebeyo() const;

    /** \brief M&eacute;todo que regresa el tamaño (el n&uacute;mero de individuos de la clase social Noble) de la ColaMedieval
     *
     * \return int Tamano de los individuos Nobles de la ColaMedieval.
     *
     */
    int ObtenerTamNoble() const;

    /** \brief M&eacute;todo que regresa el ultimo individuo de la ColaMedieval.
     *
     * \return std::string nombre del &uacute;ltimo individuo.
     *
     */
    std::string ObtenerFondo() const;

    /** \brief M&eacute;todo que regresa el primer individuo de la ColaMedieval.
     *
     * \return std::string nombre del primer individuo.
     *
     */
    std::string ObtenerFrente() const;

    /** \brief M&eacute;todo que regresa la clase Social del primer individuo de la ColaMedieval.
     *
     * \return std::string que indica la clase Social del primer individuo. (Plebeyo o Noble)
     *
     */
    std::string ObtenerClaseSocialFrente() const;

    /** \brief M&eacute;todo que retorna si la ColaMedieval est&aacute; v&iacute;cia.
     *
     * \return bool true: si la ColaMedieval esta vacia, false si no
     *
     */
    bool EstaVacia() const;

    /** \brief M&eacute;todo para vaciar la ColaMedieval.
     *
     * \return void
     *
     */
    void Vaciar();

    /** \brief M&eacute;todo que imprime todo el contenido de la ColaMedieval.
     *
     * \return void
     *
     */
    void ImprimirSinFrente() const;

    void Imprimir() const;

private:

    /** \brief Atributo Tamano de la ColaMedieval.
     *
     */
    int tam;
    /** \brief Atributo Tamano de los individuos Nobles de la ColaMedieval.
     *
     */
    int tamNoble;
    /** \brief Atributo Tamano de los individuos Plebeyos de la ColaMedieval.
     *
     */
    int tamPlebeyo;

    /** \brief Atributo Individuo de la ColaMedieval, que representa cada persona.
     *
     */
    struct Individuo
    {
        std::string nombre;
        std::string claseSocial;
        Individuo *siguiente;

        Individuo(std::string nom, std::string cs, Individuo *sig) : nombre(nom), claseSocial(cs), siguiente(sig) {}
    };

    Individuo *fondo;
    Individuo *fondoNoble;
};

#endif // ColaMedievalMEDIEVAL_HPP_INCLUDED
