using System;

namespace DecisionMaking {
   class Program {
     // C#
     static void Main(string[] args) {
        // SLETT
        int minutter = 2;
        int nummer = 1;

        bool dametoalett = true;
        bool herretoalett = false;

        if (minutter > 2) {
           herretoalett = false;
        } else {
           if (nummer == 2) {
              herretoalett = false;
           } else if (nummer == 1) {
              herretoalett = true;
           } else {
              Console.WriteLine("Hva driver du med...");
           }
        }

        string print = herretoalett.ToString();
        Console.WriteLine("{0}", print);
      }
   }
}
