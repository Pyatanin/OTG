// ��������� ������ � ������ � �������.
//
// 7. ����������, ���������� �� ������� ����� ����� ��������� ��������� � ����������������� �����. 
// ���� � ������ ������������ � ���� �������.
// 
// ����� � �������.
// ���������: ������� �., ������ �., ������ �., �������� �. (��-93)
// �����: ������� �.

#include <iostream>
#include <iomanip>
#include <vector>

std::vector<bool> marks;

bool doDfs(size_t source, size_t destination, const std::vector<std::vector<double>> &graph)
{
   marks[source] = true;
   if (source != destination)
   {
      for (size_t i = 0; i < graph[source].size(); ++i)
      {
         if (graph[source][i] != -1 && !marks[i])
            if (doDfs(i, destination, graph))
            {
               std::cout << "<-" << source + 1; //�� ��������
               return true;
            }
      }

      return false;
   }
   else
   {
      std::cout << "route: " << destination + 1; //�� ��������
      return true;
   }
}

int main()
{
   std::ios::sync_with_stdio(false);
   std::cin.tie(NULL);

   size_t n, source, destination; 
   std::cin >> n >> source >> destination;

   std::vector<std::vector<double>> graph(n, std::vector<double>(n, -1)); 
   size_t a, b;
   double w = 2.;
   while (std::cin >> a >> b)
   {
      graph[a - 1][b - 1] = w; 
      graph[b - 1][a - 1] = w;
   }

   for (size_t i = 0; i < graph.size(); ++i)
   {
      for (size_t j = 0; j < graph[i].size(); ++j)
      {
         std::cout << graph[i][j] << '\t';
      }
      std::cout << std::endl;
   }

   marks.assign(n, false);

   auto startTime = std::chrono::high_resolution_clock::now();

   if (!(doDfs(source - 1, destination - 1, graph)))
      std::cout << "Route is absent" << std::endl;

   auto endTime = std::chrono::high_resolution_clock::now() - startTime;
   auto elaplsedTime = std::chrono::duration<double>(endTime).count();
   
   std::cout << elapsedTime << std::endl;

   return 0;
}
