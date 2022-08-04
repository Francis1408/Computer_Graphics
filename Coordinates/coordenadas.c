#include "coordenadas.h"
#include <math.h>
#include <stdio.h>

/// multiplica um vetor por um escalar
/// este é um exemplo entregue pronto pra você ;)
vetor multiplicaPorEscalar(vetor v, escalar alpha)
{
    vetor resultado =
    {
        v.x * alpha,
        v.y * alpha,
        v.z * alpha,
        v.w * alpha
    };
    return resultado;
}

vetor somaVetorComVetor(vetor v, vetor u)
{
    vetor resultado =
    {
        (v.x + u.x),
        (v.y + u.y),
        (v.z + u.z),
        (v.w + u.w)
    };
    return resultado;
}

vetor diferencaVetorComVetor(vetor v, vetor u)
{
    vetor resultado =
    {
        (v.x - u.x),
        (v.y - u.y),
        (v.z - u.z),
        (v.w - u.w)
    };
    return resultado;
}

vetor diferencaEntrePontos(ponto p, ponto q)
{
    vetor resultado =
    {
        (p.x - q.x),
        (p.y - q.y),
        (p.z - q.z),
        (p.w - q.w)
    };
    return resultado;
}

ponto somaPontoComVetor(ponto p, vetor v)
{
    ponto resultado = {
        (v.x + p.x),
        (v.y + p.y),
        (v.z + p.z),
        (v.w + p.w)
    };
    return resultado;
}

escalar normaDoVetor(vetor v)
{
    escalar resultado = {
       sqrt(pow(v.x,2)+pow(v.y,2)+
             pow(v.z,2)+pow(v.w,2))
    };
    return resultado;
}

vetor normalizado(vetor v)
{
    vetor resultado = {
        (v.x/normaDoVetor(v)),
        (v.y/normaDoVetor(v)),
        (v.z/normaDoVetor(v)),
        (v.w/normaDoVetor(v))
    };
    return resultado;
}

escalar distanciaEntrePontos(ponto p, ponto q)
{
    escalar resultado = {
        sqrt(pow((p.x-q.x),2)+pow((p.y-q.y),2)+
             pow((p.z-q.z),2)+pow((p.w-q.w),2))
    };
    return resultado;
}

escalar produtoEscalar(vetor v, vetor u)
{

    escalar resultado = {
        (v.x*u.x)+(v.y*u.y)+(v.z*u.z)+(v.w*u.w)
    };
    return resultado;
}

vetor produtoVetorial(vetor v, vetor u)
{
    vetor resultado = {
        ((v.y*u.z)-(v.z*u.y)),
        -((v.x*u.z)-(v.z*u.x)),
        ((v.x*u.y)-(v.y-u.x)),
        0
    };
    return resultado;
}

///
/// Referências: http://localhost:8080/classes/geometry/#30
escalar anguloEntreVetores(vetor v, vetor u)
{
    escalar resultado = {
        acos(produtoEscalar(normalizado(v),normalizado(u)))
    };
    return resultado;
}

///
/// Referências: http://localhost:8080/classes/geometry/#22
ponto combinacaoAfim2Pontos(ponto p, ponto q, escalar alpha)
{
    ponto resultado = {
        (p.x + q.x)*alpha,
        (p.y + q.y)*alpha,
        (p.z + q.z)*alpha,
        (p.w + q.w)*alpha
    };
    return resultado;
}

/// Imprime um vetor ou ponto no terminal
/// Uso:
///   vetor r = somaVetorComVetor(a, b);
///   imprime("vetor r", r);
void imprime(struct coordenadas c, char* nome)
{
    printf("%s = { %.2f, %.2f, %.2f, %.2f }\n", nome, c.x, c.y, c.z, c.w);
}
