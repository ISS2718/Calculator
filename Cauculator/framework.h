// header.h: arquivo de inclusão para arquivos de inclusão padrão do sistema,
// ou arquivos de inclusão específicos a um projeto
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Excluir itens raramente utilizados dos cabeçalhos do Windows
// Arquivos de Cabeçalho do Windows
#include <windows.h>
// Arquivos de Cabeçalho C RunTime
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <wx/wxprec.h>
#include <stack>
#include <math.h>
#include "ALL_IDs.h"
#ifdef WX_PRECOMP
#include <wx/wx.h>
#endif