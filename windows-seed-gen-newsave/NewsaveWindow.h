#pragma once
#include <cstdint>
#include <map>
#include "Floors.h"
#include "Newsave.h"
#define NOTHING -1

namespace CppCLRWinFormsProject
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for NewsaveWindow
    /// </summary>
    public ref class NewsaveWindow : public System::Windows::Forms::Form
    {
    public:
        NewsaveWindow(void)
        {
            InitializeComponent();
            this->MaximizeBox = false;
            //
            //TODO: Add the constructor code here
            //
        }

        void add_data_to_dropdowns(Generic::Dictionary<int, String^>^ items)
        {
            for each (Control^ control in this->Controls)
            {
                if (control->GetType() == ComboBox::typeid)
                {
                    auto box = static_cast<ComboBox^>(control);

                    if (box == mine1 || box == shoguul || box == shoguul_item1) continue;

                    auto bs = gcnew BindingSource();
                    bs->DataSource = items;

                    box->ValueMember = "Key";
                    box->DisplayMember = "Value";

                    box->DataSource = bs;
                }
            }
        }

        void init_dropdowns()
        {
            Generic::Dictionary<int, String^>^ items = gcnew Generic::Dictionary<int, String^>();
            items->Add(0, "Bottled Lightning");
            items->Add(1, "Butcher's Cleaver");
            items->Add(2, "Bombushka");
            items->Add(3, "Golden Popcorn");
            items->Add(4, "Guidance");
            items->Add(5, "Phantasmal Axe");
            items->Add(6, "Floating Skull");
            items->Add(7, "Salamander Tail");
            items->Add(8, "Fork");

            auto bs = gcnew BindingSource();
            bs->DataSource = items;

            mine1->ValueMember = "Key";
            mine1->DisplayMember = "Value";

            mine1->DataSource = bs;

            items = gcnew Generic::Dictionary<int, String^>();

            items->Add(NOTHING, "Nothing");
            items->Add(2, "mine2");
            items->Add(3, "mine3");
            items->Add(4, "mine4");
            items->Add(6, "dungeon1");
            items->Add(7, "dungeon2");
            items->Add(8, "dungeon3");
            items->Add(9, "dungeon4");
            items->Add(11, "halls1");
            items->Add(12, "halls2");
            items->Add(13, "halls3");
            items->Add(14, "halls4");
            items->Add(16, "caverns1");
            items->Add(17, "caverns2");
            items->Add(18, "caverns3");
            items->Add(19, "caverns4");
            items->Add(21, "core1");
            items->Add(22, "core2");
            items->Add(23, "core3");
            items->Add(24, "core4");

            bs = gcnew BindingSource();
            bs->DataSource = items;

            shoguul->ValueMember = "Key";
            shoguul->DisplayMember = "Value";

            shoguul->DataSource = bs;

            items = gcnew Generic::Dictionary<int, String^>();

            items->Add(0, "Lockpick");
            items->Add(1, "Chakram");
            items->Add(2, "Karmic Scale");
            items->Add(3, "Rabbit Gloves");
            items->Add(4, "Doom Blade");
            items->Add(5, "Mjolnir");
            items->Add(6, "Pocket of Holding");
            items->Add(7, "Miniaturizer");
            items->Add(8, "Nullstone");
            items->Add(9, "Mushroom");
            items->Add(10, "Glass Cannon");
            items->Add(11, "Branding Bomb");
            items->Add(12, "Suneater");
            items->Add(13, "Transmutagen Blast");
            items->Add(14, "Tsar Bomba");
            items->Add(15, "Shield of Quills");
            items->Add(16, "Soul Guard");
            items->Add(17, "Box of Holding");
            items->Add(18, "Stoneforge Broth");

            bs = gcnew BindingSource();
            bs->DataSource = items;

            shoguul_item1->ValueMember = "Key";
            shoguul_item1->DisplayMember = "Value";

            shoguul_item1->DataSource = bs;


            items = gcnew Generic::Dictionary<int, String^>();

            items->Add(NOTHING, "Nothing");
            items->Add(0, "Bombushka");
            items->Add(1, "Seer's Blood");
            items->Add(2, "Rook's Bomb");
            items->Add(3, "Lightning Bomb");
            items->Add(4, "Galoshes");
            items->Add(5, "Bottled Lightning");
            items->Add(6, "Salamander Tail");
            items->Add(7, "Guidance");
            items->Add(8, "Ursine Ring");
            items->Add(9, "Demon Ring");
            items->Add(10, "Intensifier");
            items->Add(11, "Cracked Orb");
            items->Add(12, "Conductor");
            items->Add(13, "Grimhilde's Mirror");
            items->Add(14, "Meal Ticket");
            items->Add(15, "Dillon's Claw");
            items->Add(16, "Bramble Vest");
            items->Add(17, "Leftovers");
            items->Add(18, "Spare Ordnance");
            items->Add(19, "Simple Chest");
            items->Add(20, "Unstable Concoction");
            items->Add(21, "Totem of Life");
            items->Add(22, "Golden Popcorn");
            items->Add(23, "Miner's Flask");
            items->Add(24, "Sewing Kit");
            items->Add(25, "Floating Skull");
            items->Add(26, "Float Boots");
            items->Add(27, "Key Blade");
            items->Add(28, "War Paint");
            items->Add(29, "Sonic Boom");
            items->Add(30, "Gold Frenzy");
            items->Add(31, "Butcher's Cleaver");
            items->Add(32, "Iron Branch");
            items->Add(33, "Knight's Pendant");
            items->Add(34, "Queen's Crown");
            items->Add(35, "Aegis");
            items->Add(36, "Adventurer's Whip");
            items->Add(37, "Axe Thrower's Pendant");
            items->Add(38, "Cosmic Egg");
            items->Add(39, "Battle Standard");
            items->Add(40, "Battle Axe");
            items->Add(41, "Tent");
            items->Add(42, "Masa");
            items->Add(43, "Lunchbox");
            items->Add(44, "Phantasmal Axe");
            items->Add(45, "Gecko Blast");
            items->Add(46, "Soul Cannon");
            items->Add(47, "Greaves");
            items->Add(48, "Pauldron");
            items->Add(49, "Obsidian Knife");
            items->Add(50, "Fork");
            items->Add(51, "Ursa Major");
            items->Add(52, "Canis Major");
            items->Add(53, "Sagitta");
            items->Add(54, "Circinus");
            items->Add(55, "Orion's Sword");
            items->Add(56, "Shrapnel");
            items->Add(57, "Tortoise Shield");
            items->Add(58, "Golden Axe");

            add_data_to_dropdowns(items);
        }


    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~NewsaveWindow()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::ComboBox^ mine1;
    protected:
    protected:
    protected:
    private:
        System::Windows::Forms::Button^ find_seeds_btn;
    private:
        System::Windows::Forms::ComboBox^ mine2;
    private:
        System::Windows::Forms::ComboBox^ mine3;
    private:
        System::Windows::Forms::NumericUpDown^ output_seeds;
    private:
        System::Windows::Forms::ComboBox^ mine4;
    private:
        System::Windows::Forms::Label^ label1;
    private:
        System::Windows::Forms::Label^ label2;
    private:
        System::Windows::Forms::Label^ label3;
    private:
        System::Windows::Forms::Label^ label4;
    private:
        System::Windows::Forms::ComboBox^ dungeon1;
    private:
        System::Windows::Forms::Label^ label5;
    private:
        System::Windows::Forms::ComboBox^ Dungeon2;
    private:
        System::Windows::Forms::Label^ label6;
    private:
        System::Windows::Forms::ComboBox^ Dungeon3;
    private:
        System::Windows::Forms::Label^ label7;
    private:
        System::Windows::Forms::ComboBox^ Dungeon4;
    private:
        System::Windows::Forms::Label^ label8;
    private:
        System::Windows::Forms::ComboBox^ halls1;
    private:
        System::Windows::Forms::ComboBox^ halls2;
    private:
        System::Windows::Forms::ComboBox^ halls3;
    private:
        System::Windows::Forms::ComboBox^ halls4;
    private:
        System::Windows::Forms::Label^ label9;
    private:
        System::Windows::Forms::Label^ label10;
    private:
        System::Windows::Forms::Label^ label11;
    private:
        System::Windows::Forms::Label^ label12;
    private:
        System::Windows::Forms::ComboBox^ caverns1;
    private:
        System::Windows::Forms::ComboBox^ caverns2;
    private:
        System::Windows::Forms::ComboBox^ caverns3;
    private:
        System::Windows::Forms::ComboBox^ caverns4;
    private:
        System::Windows::Forms::Label^ label13;
    private:
        System::Windows::Forms::Label^ label14;
    private:
        System::Windows::Forms::Label^ label15;
    private:
        System::Windows::Forms::Label^ label16;
    private:
        System::Windows::Forms::ComboBox^ core1;
    private:
        System::Windows::Forms::ComboBox^ core2;
    private:
        System::Windows::Forms::Label^ label17;
    private:
        System::Windows::Forms::Label^ label18;
    private:
        System::Windows::Forms::ComboBox^ core3;
    private:
        System::Windows::Forms::ComboBox^ core4;
    private:
        System::Windows::Forms::Label^ label19;
    private:
        System::Windows::Forms::Label^ label20;
    private:
        System::Windows::Forms::Label^ label21;
    private:
        System::Windows::Forms::Label^ label22;
    private:
        System::Windows::Forms::NumericUpDown^ search_seeds;
    private:
    private:
        System::Windows::Forms::RichTextBox^ outputbox;
    private:
        System::Windows::Forms::Label^ label23;
    private:
        System::Windows::Forms::ComboBox^ shoguul;
    private:
        System::Windows::Forms::ComboBox^ shoguul_item1;
    private:
    private:
        System::Windows::Forms::Label^ label24;


    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->mine1 = (gcnew System::Windows::Forms::ComboBox());
            this->find_seeds_btn = (gcnew System::Windows::Forms::Button());
            this->mine2 = (gcnew System::Windows::Forms::ComboBox());
            this->mine3 = (gcnew System::Windows::Forms::ComboBox());
            this->output_seeds = (gcnew System::Windows::Forms::NumericUpDown());
            this->mine4 = (gcnew System::Windows::Forms::ComboBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->dungeon1 = (gcnew System::Windows::Forms::ComboBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->Dungeon2 = (gcnew System::Windows::Forms::ComboBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->Dungeon3 = (gcnew System::Windows::Forms::ComboBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->Dungeon4 = (gcnew System::Windows::Forms::ComboBox());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->halls1 = (gcnew System::Windows::Forms::ComboBox());
            this->halls2 = (gcnew System::Windows::Forms::ComboBox());
            this->halls3 = (gcnew System::Windows::Forms::ComboBox());
            this->halls4 = (gcnew System::Windows::Forms::ComboBox());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->caverns1 = (gcnew System::Windows::Forms::ComboBox());
            this->caverns2 = (gcnew System::Windows::Forms::ComboBox());
            this->caverns3 = (gcnew System::Windows::Forms::ComboBox());
            this->caverns4 = (gcnew System::Windows::Forms::ComboBox());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->core1 = (gcnew System::Windows::Forms::ComboBox());
            this->core2 = (gcnew System::Windows::Forms::ComboBox());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->core3 = (gcnew System::Windows::Forms::ComboBox());
            this->core4 = (gcnew System::Windows::Forms::ComboBox());
            this->label19 = (gcnew System::Windows::Forms::Label());
            this->label20 = (gcnew System::Windows::Forms::Label());
            this->label21 = (gcnew System::Windows::Forms::Label());
            this->label22 = (gcnew System::Windows::Forms::Label());
            this->search_seeds = (gcnew System::Windows::Forms::NumericUpDown());
            this->outputbox = (gcnew System::Windows::Forms::RichTextBox());
            this->label23 = (gcnew System::Windows::Forms::Label());
            this->shoguul = (gcnew System::Windows::Forms::ComboBox());
            this->shoguul_item1 = (gcnew System::Windows::Forms::ComboBox());
            this->label24 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->output_seeds))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->search_seeds))->BeginInit();
            this->SuspendLayout();
            // 
            // mine1
            // 
            this->mine1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->mine1->FormattingEnabled = true;
            this->mine1->Location = System::Drawing::Point(50, 37);
            this->mine1->Name = L"mine1";
            this->mine1->Size = System::Drawing::Size(121, 24);
            this->mine1->TabIndex = 0;
            // 
            // find_seeds_btn
            // 
            this->find_seeds_btn->Location = System::Drawing::Point(325, 450);
            this->find_seeds_btn->Name = L"find_seeds_btn";
            this->find_seeds_btn->Size = System::Drawing::Size(194, 45);
            this->find_seeds_btn->TabIndex = 1;
            this->find_seeds_btn->Text = L"Find Seeds";
            this->find_seeds_btn->UseVisualStyleBackColor = true;
            this->find_seeds_btn->Click += gcnew System::EventHandler(this, &NewsaveWindow::find_seeds_btn_Click);
            // 
            // mine2
            // 
            this->mine2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->mine2->FormattingEnabled = true;
            this->mine2->Location = System::Drawing::Point(250, 37);
            this->mine2->Name = L"mine2";
            this->mine2->Size = System::Drawing::Size(121, 24);
            this->mine2->TabIndex = 2;
            // 
            // mine3
            // 
            this->mine3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->mine3->FormattingEnabled = true;
            this->mine3->Location = System::Drawing::Point(450, 37);
            this->mine3->Name = L"mine3";
            this->mine3->Size = System::Drawing::Size(121, 24);
            this->mine3->TabIndex = 3;
            // 
            // output_seeds
            // 
            this->output_seeds->Increment = System::Decimal(gcnew cli::array<System::Int32>(4){5, 0, 0, 0});
            this->output_seeds->Location = System::Drawing::Point(78, 441);
            this->output_seeds->Maximum = System::Decimal(gcnew cli::array<System::Int32>(4){1000, 0, 0, 0});
            this->output_seeds->Minimum = System::Decimal(gcnew cli::array<System::Int32>(4){1, 0, 0, 0});
            this->output_seeds->Name = L"output_seeds";
            this->output_seeds->Size = System::Drawing::Size(120, 22);
            this->output_seeds->TabIndex = 4;
            this->output_seeds->Value = System::Decimal(gcnew cli::array<System::Int32>(4){50, 0, 0, 0});
            // 
            // mine4
            // 
            this->mine4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->mine4->FormattingEnabled = true;
            this->mine4->Location = System::Drawing::Point(650, 37);
            this->mine4->Name = L"mine4";
            this->mine4->Size = System::Drawing::Size(121, 24);
            this->mine4->TabIndex = 4;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(75, 18);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(75, 16);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Goldmine 1";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(275, 18);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(75, 16);
            this->label2->TabIndex = 6;
            this->label2->Text = L"Goldmine 2";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(475, 18);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(75, 16);
            this->label3->TabIndex = 7;
            this->label3->Text = L"Goldmine 3";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(675, 18);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(75, 16);
            this->label4->TabIndex = 8;
            this->label4->Text = L"Goldmine 4";
            // 
            // dungeon1
            // 
            this->dungeon1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->dungeon1->FormattingEnabled = true;
            this->dungeon1->Location = System::Drawing::Point(50, 123);
            this->dungeon1->Name = L"dungeon1";
            this->dungeon1->Size = System::Drawing::Size(121, 24);
            this->dungeon1->TabIndex = 6;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(75, 104);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(72, 16);
            this->label5->TabIndex = 10;
            this->label5->Text = L"Dungeon 1";
            // 
            // Dungeon2
            // 
            this->Dungeon2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->Dungeon2->FormattingEnabled = true;
            this->Dungeon2->Location = System::Drawing::Point(250, 123);
            this->Dungeon2->Name = L"Dungeon2";
            this->Dungeon2->Size = System::Drawing::Size(121, 24);
            this->Dungeon2->TabIndex = 7;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(275, 104);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(72, 16);
            this->label6->TabIndex = 12;
            this->label6->Text = L"Dungeon 2";
            // 
            // Dungeon3
            // 
            this->Dungeon3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->Dungeon3->FormattingEnabled = true;
            this->Dungeon3->Location = System::Drawing::Point(450, 123);
            this->Dungeon3->Name = L"Dungeon3";
            this->Dungeon3->Size = System::Drawing::Size(121, 24);
            this->Dungeon3->TabIndex = 8;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(475, 104);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(72, 16);
            this->label7->TabIndex = 13;
            this->label7->Text = L"Dungeon 3";
            // 
            // Dungeon4
            // 
            this->Dungeon4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->Dungeon4->FormattingEnabled = true;
            this->Dungeon4->Location = System::Drawing::Point(650, 123);
            this->Dungeon4->Name = L"Dungeon4";
            this->Dungeon4->Size = System::Drawing::Size(121, 24);
            this->Dungeon4->TabIndex = 9;
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(675, 104);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(72, 16);
            this->label8->TabIndex = 14;
            this->label8->Text = L"Dungeon 4";
            // 
            // halls1
            // 
            this->halls1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->halls1->FormattingEnabled = true;
            this->halls1->Location = System::Drawing::Point(50, 209);
            this->halls1->Name = L"halls1";
            this->halls1->Size = System::Drawing::Size(121, 24);
            this->halls1->TabIndex = 11;
            // 
            // halls2
            // 
            this->halls2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->halls2->FormattingEnabled = true;
            this->halls2->Location = System::Drawing::Point(250, 209);
            this->halls2->Name = L"halls2";
            this->halls2->Size = System::Drawing::Size(121, 24);
            this->halls2->TabIndex = 12;
            // 
            // halls3
            // 
            this->halls3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->halls3->FormattingEnabled = true;
            this->halls3->Location = System::Drawing::Point(450, 209);
            this->halls3->Name = L"halls3";
            this->halls3->Size = System::Drawing::Size(121, 24);
            this->halls3->TabIndex = 13;
            // 
            // halls4
            // 
            this->halls4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->halls4->FormattingEnabled = true;
            this->halls4->Location = System::Drawing::Point(650, 209);
            this->halls4->Name = L"halls4";
            this->halls4->Size = System::Drawing::Size(121, 24);
            this->halls4->TabIndex = 14;
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(85, 190);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(48, 16);
            this->label9->TabIndex = 19;
            this->label9->Text = L"Halls 1";
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Location = System::Drawing::Point(285, 190);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(48, 16);
            this->label10->TabIndex = 20;
            this->label10->Text = L"Halls 2";
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Location = System::Drawing::Point(485, 190);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(48, 16);
            this->label11->TabIndex = 21;
            this->label11->Text = L"Halls 3";
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Location = System::Drawing::Point(685, 190);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(48, 16);
            this->label12->TabIndex = 22;
            this->label12->Text = L"Halls 4";
            // 
            // caverns1
            // 
            this->caverns1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->caverns1->FormattingEnabled = true;
            this->caverns1->Location = System::Drawing::Point(50, 295);
            this->caverns1->Name = L"caverns1";
            this->caverns1->Size = System::Drawing::Size(121, 24);
            this->caverns1->TabIndex = 16;
            // 
            // caverns2
            // 
            this->caverns2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->caverns2->FormattingEnabled = true;
            this->caverns2->Location = System::Drawing::Point(250, 295);
            this->caverns2->Name = L"caverns2";
            this->caverns2->Size = System::Drawing::Size(121, 24);
            this->caverns2->TabIndex = 17;
            // 
            // caverns3
            // 
            this->caverns3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->caverns3->FormattingEnabled = true;
            this->caverns3->Location = System::Drawing::Point(450, 295);
            this->caverns3->Name = L"caverns3";
            this->caverns3->Size = System::Drawing::Size(121, 24);
            this->caverns3->TabIndex = 18;
            // 
            // caverns4
            // 
            this->caverns4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->caverns4->FormattingEnabled = true;
            this->caverns4->Location = System::Drawing::Point(650, 295);
            this->caverns4->Name = L"caverns4";
            this->caverns4->Size = System::Drawing::Size(121, 24);
            this->caverns4->TabIndex = 19;
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->Location = System::Drawing::Point(75, 276);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(67, 16);
            this->label13->TabIndex = 26;
            this->label13->Text = L"Caverns 1";
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->Location = System::Drawing::Point(275, 276);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(67, 16);
            this->label14->TabIndex = 27;
            this->label14->Text = L"Caverns 2";
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->Location = System::Drawing::Point(475, 276);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(67, 16);
            this->label15->TabIndex = 28;
            this->label15->Text = L"Caverns 3";
            // 
            // label16
            // 
            this->label16->AutoSize = true;
            this->label16->Location = System::Drawing::Point(675, 276);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(67, 16);
            this->label16->TabIndex = 29;
            this->label16->Text = L"Caverns 4";
            // 
            // core1
            // 
            this->core1->AllowDrop = true;
            this->core1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->core1->FormattingEnabled = true;
            this->core1->Location = System::Drawing::Point(50, 368);
            this->core1->Name = L"core1";
            this->core1->Size = System::Drawing::Size(121, 24);
            this->core1->TabIndex = 21;
            // 
            // core2
            // 
            this->core2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->core2->FormattingEnabled = true;
            this->core2->Location = System::Drawing::Point(250, 368);
            this->core2->Name = L"core2";
            this->core2->Size = System::Drawing::Size(121, 24);
            this->core2->TabIndex = 22;
            // 
            // label17
            // 
            this->label17->AutoSize = true;
            this->label17->Location = System::Drawing::Point(87, 349);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(46, 16);
            this->label17->TabIndex = 30;
            this->label17->Text = L"Core 1";
            // 
            // label18
            // 
            this->label18->AutoSize = true;
            this->label18->Location = System::Drawing::Point(287, 349);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(46, 16);
            this->label18->TabIndex = 31;
            this->label18->Text = L"Core 2";
            // 
            // core3
            // 
            this->core3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->core3->FormattingEnabled = true;
            this->core3->Location = System::Drawing::Point(450, 368);
            this->core3->Name = L"core3";
            this->core3->Size = System::Drawing::Size(121, 24);
            this->core3->TabIndex = 23;
            // 
            // core4
            // 
            this->core4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->core4->FormattingEnabled = true;
            this->core4->Location = System::Drawing::Point(650, 368);
            this->core4->Name = L"core4";
            this->core4->Size = System::Drawing::Size(121, 24);
            this->core4->TabIndex = 24;
            // 
            // label19
            // 
            this->label19->AutoSize = true;
            this->label19->Location = System::Drawing::Point(487, 349);
            this->label19->Name = L"label19";
            this->label19->Size = System::Drawing::Size(46, 16);
            this->label19->TabIndex = 32;
            this->label19->Text = L"Core 3";
            // 
            // label20
            // 
            this->label20->AutoSize = true;
            this->label20->Location = System::Drawing::Point(687, 349);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(46, 16);
            this->label20->TabIndex = 33;
            this->label20->Text = L"Core 4";
            // 
            // label21
            // 
            this->label21->AutoSize = true;
            this->label21->Location = System::Drawing::Point(36, 422);
            this->label21->Name = L"label21";
            this->label21->Size = System::Drawing::Size(205, 16);
            this->label21->TabIndex = 34;
            this->label21->Text = L"Amount of seeds you\'d like to find";
            // 
            // label22
            // 
            this->label22->AutoSize = true;
            this->label22->Location = System::Drawing::Point(39, 466);
            this->label22->Name = L"label22";
            this->label22->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->label22->Size = System::Drawing::Size(212, 16);
            this->label22->TabIndex = 35;
            this->label22->Text = L"Amount of seeds to search through";
            // 
            // search_seeds
            // 
            this->search_seeds->Increment = System::Decimal(gcnew cli::array<System::Int32>(4){100, 0, 0, 0});
            this->search_seeds->Location = System::Drawing::Point(78, 485);
            this->search_seeds->Maximum = System::Decimal(gcnew cli::array<System::Int32>(4){100000000, 0, 0, 0});
            this->search_seeds->Minimum = System::Decimal(gcnew cli::array<System::Int32>(4){1, 0, 0, 0});
            this->search_seeds->Name = L"search_seeds";
            this->search_seeds->Size = System::Drawing::Size(120, 22);
            this->search_seeds->TabIndex = 36;
            this->search_seeds->Value = System::Decimal(gcnew cli::array<System::Int32>(4){10000000, 0, 0, 0});
            // 
            // outputbox
            // 
            this->outputbox->BackColor = System::Drawing::SystemColors::WindowText;
            this->outputbox->ForeColor = System::Drawing::SystemColors::ControlLight;
            this->outputbox->Location = System::Drawing::Point(589, 419);
            this->outputbox->Name = L"outputbox";
            this->outputbox->ReadOnly = true;
            this->outputbox->Size = System::Drawing::Size(239, 96);
            this->outputbox->TabIndex = 37;
            this->outputbox->Text = L"";
            // 
            // label23
            // 
            this->label23->AutoSize = true;
            this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F,
                                                               System::Drawing::FontStyle::Regular,
                                                               System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(0)));
            this->label23->Location = System::Drawing::Point(847, 177);
            this->label23->Name = L"label23";
            this->label23->Size = System::Drawing::Size(102, 29);
            this->label23->TabIndex = 38;
            this->label23->Text = L"Shoguul";
            // 
            // shoguul
            // 

            this->shoguul->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->shoguul->FormattingEnabled = true;
            this->shoguul->Location = System::Drawing::Point(837, 209);
            this->shoguul->Name = L"shoguul";
            this->shoguul->Size = System::Drawing::Size(121, 24);
            this->shoguul->TabIndex = 39;
            // 
            // shoguul_item1
            // 
            this->shoguul_item1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->shoguul_item1->FormattingEnabled = true;
            this->shoguul_item1->Location = System::Drawing::Point(837, 294);
            this->shoguul_item1->Name = L"shoguul_item1";
            this->shoguul_item1->Size = System::Drawing::Size(121, 24);
            this->shoguul_item1->TabIndex = 40;
            // 
            // label24
            // 
            this->label24->AutoSize = true;
            this->label24->Location = System::Drawing::Point(879, 275);
            this->label24->Name = L"label24";
            this->label24->Size = System::Drawing::Size(35, 16);
            this->label24->TabIndex = 42;
            this->label24->Text = L"Item:";
            // 
            // NewsaveWindow
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->BackColor = System::Drawing::SystemColors::Menu;
            this->ClientSize = System::Drawing::Size(982, 533);
            this->Controls->Add(this->label24);
            this->Controls->Add(this->shoguul_item1);
            this->Controls->Add(this->shoguul);
            this->Controls->Add(this->label23);
            this->Controls->Add(this->outputbox);
            this->Controls->Add(this->search_seeds);
            this->Controls->Add(this->label22);
            this->Controls->Add(this->label21);
            this->Controls->Add(this->label20);
            this->Controls->Add(this->label19);
            this->Controls->Add(this->core4);
            this->Controls->Add(this->core3);
            this->Controls->Add(this->label18);
            this->Controls->Add(this->label17);
            this->Controls->Add(this->core2);
            this->Controls->Add(this->core1);
            this->Controls->Add(this->label16);
            this->Controls->Add(this->label15);
            this->Controls->Add(this->label14);
            this->Controls->Add(this->label13);
            this->Controls->Add(this->caverns4);
            this->Controls->Add(this->caverns3);
            this->Controls->Add(this->caverns2);
            this->Controls->Add(this->caverns1);
            this->Controls->Add(this->label12);
            this->Controls->Add(this->label11);
            this->Controls->Add(this->label10);
            this->Controls->Add(this->label9);
            this->Controls->Add(this->halls4);
            this->Controls->Add(this->halls3);
            this->Controls->Add(this->halls2);
            this->Controls->Add(this->halls1);
            this->Controls->Add(this->label8);
            this->Controls->Add(this->Dungeon4);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->Dungeon3);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->Dungeon2);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->dungeon1);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->mine4);
            this->Controls->Add(this->output_seeds);
            this->Controls->Add(this->mine3);
            this->Controls->Add(this->mine2);
            this->Controls->Add(this->find_seeds_btn);
            this->Controls->Add(this->mine1);
            this->Name = L"NewsaveWindow";
            this->Text = L"Newsave Seed Gen (cool version)";
            this->Load += gcnew System::EventHandler(this, &NewsaveWindow::NewsaveWindow_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->output_seeds))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->search_seeds))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
    private:
        std::string ToStdString(String^ input)
        {
            using namespace System::Runtime::InteropServices;
            const auto chars = static_cast<const char*>((Marshal::StringToHGlobalAnsi(input)).ToPointer());
            std::string output(chars);
            Marshal::FreeHGlobal(IntPtr((void*)chars));
            return output;
        }

        System::Void find_seeds_btn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            std::map<uint_fast8_t, std::string> room_names;
            std::map<uint_fast8_t, uint_fast8_t> rooms;
            std::string shoguul_floor_name = "";

            for each (Control^ control in this->Controls)
            {
                if (control->GetType() == ComboBox::typeid)
                {
                    auto box = static_cast<ComboBox^>(control);
                    const auto item_index = static_cast<int>(box->SelectedValue);

                    if (box->TabIndex == static_cast<int>(shoguul->SelectedValue))
                        shoguul_floor_name = ToStdString(box->Name);


                    if (item_index == NOTHING || box == mine1 || box == shoguul || box == shoguul_item1)
                        continue;

                    rooms[box->TabIndex] = item_index;
                    room_names[box->TabIndex] = ToStdString(box->Name);
                }
            }


            const auto floors = Floors(static_cast<int>(mine1->SelectedValue), rooms, room_names,
                                       Shoguul(static_cast<int>(shoguul->SelectedValue),
                                               static_cast<int>(shoguul_item1->SelectedValue), shoguul_floor_name));

            Newsave::calculate_seeds(floors, static_cast<int>(output_seeds->Value),
                                     static_cast<uint_fast32_t>(search_seeds->Value));

            outputbox->Text = "";

            std::ifstream file;
            file.open("output.txt");

            if (file.is_open())
            {
                std::string line;
                while (std::getline(file, line))
                    outputbox->AppendText(gcnew System::String((line + "\n").c_str()));

                file.close();
            }
            else
                outputbox->Text = "Unable to get data";
        }

    private:
        System::Void NewsaveWindow_Load(System::Object^ sender, System::EventArgs^ e)
        {
            init_dropdowns();
        }
    };
}
