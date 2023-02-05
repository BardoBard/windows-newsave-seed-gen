#pragma once
#include "Newsave.h"
#include "Output.h"

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
            items->Add(-1, "Anything");
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
        System::Windows::Forms::NumericUpDown^ amount_of_seeds_to_find;

    private:
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
        System::Windows::Forms::NumericUpDown^ amount_of_seeds_to_loop;
    private:
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
        System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::TabControl^ tabControl1;
private: System::Windows::Forms::TabPage^ tabPage1;
private: System::Windows::Forms::TabPage^ tabPage2;
private: System::Windows::Forms::PictureBox^ pictureBox3;
private: System::Windows::Forms::PictureBox^ pictureBox2;
private: System::Windows::Forms::PictureBox^ pictureBox1;
private: System::Windows::Forms::PictureBox^ pictureBox11;
private: System::Windows::Forms::PictureBox^ pictureBox12;
private: System::Windows::Forms::PictureBox^ pictureBox13;
private: System::Windows::Forms::PictureBox^ pictureBox14;
private: System::Windows::Forms::PictureBox^ pictureBox15;
private: System::Windows::Forms::PictureBox^ pictureBox16;
private: System::Windows::Forms::PictureBox^ pictureBox17;
private: System::Windows::Forms::PictureBox^ pictureBox18;
private: System::Windows::Forms::PictureBox^ pictureBox19;
private: System::Windows::Forms::PictureBox^ pictureBox20;
private: System::Windows::Forms::PictureBox^ pictureBox6;
private: System::Windows::Forms::PictureBox^ pictureBox7;
private: System::Windows::Forms::PictureBox^ pictureBox8;
private: System::Windows::Forms::PictureBox^ pictureBox9;
private: System::Windows::Forms::PictureBox^ pictureBox10;
private: System::Windows::Forms::PictureBox^ pictureBox5;
private: System::Windows::Forms::PictureBox^ pictureBox4;



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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NewsaveWindow::typeid));
            this->mine1 = (gcnew System::Windows::Forms::ComboBox());
            this->find_seeds_btn = (gcnew System::Windows::Forms::Button());
            this->mine2 = (gcnew System::Windows::Forms::ComboBox());
            this->mine3 = (gcnew System::Windows::Forms::ComboBox());
            this->amount_of_seeds_to_find = (gcnew System::Windows::Forms::NumericUpDown());
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
            this->amount_of_seeds_to_loop = (gcnew System::Windows::Forms::NumericUpDown());
            this->outputbox = (gcnew System::Windows::Forms::RichTextBox());
            this->label23 = (gcnew System::Windows::Forms::Label());
            this->shoguul = (gcnew System::Windows::Forms::ComboBox());
            this->shoguul_item1 = (gcnew System::Windows::Forms::ComboBox());
            this->label24 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
            this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox17 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox18 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox19 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox20 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount_of_seeds_to_find))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount_of_seeds_to_loop))->BeginInit();
            this->tabControl1->SuspendLayout();
            this->tabPage1->SuspendLayout();
            this->tabPage2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->BeginInit();
            this->SuspendLayout();
            // 
            // mine1
            // 
            this->mine1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->mine1->FormattingEnabled = true;
            this->mine1->Location = System::Drawing::Point(19, 26);
            this->mine1->Margin = System::Windows::Forms::Padding(2);
            this->mine1->Name = L"mine1";
            this->mine1->Size = System::Drawing::Size(92, 21);
            this->mine1->TabIndex = 1;
            // 
            // find_seeds_btn
            // 
            this->find_seeds_btn->Location = System::Drawing::Point(292, 361);
            this->find_seeds_btn->Margin = System::Windows::Forms::Padding(2);
            this->find_seeds_btn->Name = L"find_seeds_btn";
            this->find_seeds_btn->Size = System::Drawing::Size(146, 37);
            this->find_seeds_btn->TabIndex = 1;
            this->find_seeds_btn->Text = L"Find Seeds";
            this->find_seeds_btn->UseVisualStyleBackColor = true;
            this->find_seeds_btn->Click += gcnew System::EventHandler(this, &NewsaveWindow::find_seeds_btn_Click);
            // 
            // mine2
            // 
            this->mine2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->mine2->FormattingEnabled = true;
            this->mine2->Location = System::Drawing::Point(169, 26);
            this->mine2->Margin = System::Windows::Forms::Padding(2);
            this->mine2->Name = L"mine2";
            this->mine2->Size = System::Drawing::Size(92, 21);
            this->mine2->TabIndex = 2;
            // 
            // mine3
            // 
            this->mine3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->mine3->FormattingEnabled = true;
            this->mine3->Location = System::Drawing::Point(319, 26);
            this->mine3->Margin = System::Windows::Forms::Padding(2);
            this->mine3->Name = L"mine3";
            this->mine3->Size = System::Drawing::Size(92, 21);
            this->mine3->TabIndex = 3;
            // 
            // amount_of_seeds_to_find
            // 
            this->amount_of_seeds_to_find->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->amount_of_seeds_to_find->Location = System::Drawing::Point(48, 357);
            this->amount_of_seeds_to_find->Margin = System::Windows::Forms::Padding(2);
            this->amount_of_seeds_to_find->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
            this->amount_of_seeds_to_find->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->amount_of_seeds_to_find->Name = L"amount_of_seeds_to_find";
            this->amount_of_seeds_to_find->Size = System::Drawing::Size(90, 20);
            this->amount_of_seeds_to_find->TabIndex = 4;
            this->amount_of_seeds_to_find->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            // 
            // mine4
            // 
            this->mine4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->mine4->FormattingEnabled = true;
            this->mine4->Location = System::Drawing::Point(469, 26);
            this->mine4->Margin = System::Windows::Forms::Padding(2);
            this->mine4->Name = L"mine4";
            this->mine4->Size = System::Drawing::Size(92, 21);
            this->mine4->TabIndex = 4;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(37, 11);
            this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(60, 13);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Goldmine 1";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(187, 11);
            this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(60, 13);
            this->label2->TabIndex = 6;
            this->label2->Text = L"Goldmine 2";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(337, 11);
            this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(60, 13);
            this->label3->TabIndex = 7;
            this->label3->Text = L"Goldmine 3";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(487, 11);
            this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(60, 13);
            this->label4->TabIndex = 8;
            this->label4->Text = L"Goldmine 4";
            // 
            // dungeon1
            // 
            this->dungeon1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->dungeon1->FormattingEnabled = true;
            this->dungeon1->Location = System::Drawing::Point(19, 96);
            this->dungeon1->Margin = System::Windows::Forms::Padding(2);
            this->dungeon1->Name = L"dungeon1";
            this->dungeon1->Size = System::Drawing::Size(92, 21);
            this->dungeon1->TabIndex = 6;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(37, 80);
            this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(60, 13);
            this->label5->TabIndex = 10;
            this->label5->Text = L"Dungeon 1";
            // 
            // Dungeon2
            // 
            this->Dungeon2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->Dungeon2->FormattingEnabled = true;
            this->Dungeon2->Location = System::Drawing::Point(169, 96);
            this->Dungeon2->Margin = System::Windows::Forms::Padding(2);
            this->Dungeon2->Name = L"Dungeon2";
            this->Dungeon2->Size = System::Drawing::Size(92, 21);
            this->Dungeon2->TabIndex = 7;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(187, 80);
            this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(60, 13);
            this->label6->TabIndex = 12;
            this->label6->Text = L"Dungeon 2";
            // 
            // Dungeon3
            // 
            this->Dungeon3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->Dungeon3->FormattingEnabled = true;
            this->Dungeon3->Location = System::Drawing::Point(319, 96);
            this->Dungeon3->Margin = System::Windows::Forms::Padding(2);
            this->Dungeon3->Name = L"Dungeon3";
            this->Dungeon3->Size = System::Drawing::Size(92, 21);
            this->Dungeon3->TabIndex = 8;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(337, 80);
            this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(60, 13);
            this->label7->TabIndex = 13;
            this->label7->Text = L"Dungeon 3";
            // 
            // Dungeon4
            // 
            this->Dungeon4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->Dungeon4->FormattingEnabled = true;
            this->Dungeon4->Location = System::Drawing::Point(469, 96);
            this->Dungeon4->Margin = System::Windows::Forms::Padding(2);
            this->Dungeon4->Name = L"Dungeon4";
            this->Dungeon4->Size = System::Drawing::Size(92, 21);
            this->Dungeon4->TabIndex = 9;
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(487, 80);
            this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(60, 13);
            this->label8->TabIndex = 14;
            this->label8->Text = L"Dungeon 4";
            // 
            // halls1
            // 
            this->halls1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->halls1->FormattingEnabled = true;
            this->halls1->Location = System::Drawing::Point(19, 166);
            this->halls1->Margin = System::Windows::Forms::Padding(2);
            this->halls1->Name = L"halls1";
            this->halls1->Size = System::Drawing::Size(92, 21);
            this->halls1->TabIndex = 11;
            // 
            // halls2
            // 
            this->halls2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->halls2->FormattingEnabled = true;
            this->halls2->Location = System::Drawing::Point(169, 166);
            this->halls2->Margin = System::Windows::Forms::Padding(2);
            this->halls2->Name = L"halls2";
            this->halls2->Size = System::Drawing::Size(92, 21);
            this->halls2->TabIndex = 12;
            // 
            // halls3
            // 
            this->halls3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->halls3->FormattingEnabled = true;
            this->halls3->Location = System::Drawing::Point(319, 166);
            this->halls3->Margin = System::Windows::Forms::Padding(2);
            this->halls3->Name = L"halls3";
            this->halls3->Size = System::Drawing::Size(92, 21);
            this->halls3->TabIndex = 13;
            // 
            // halls4
            // 
            this->halls4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->halls4->FormattingEnabled = true;
            this->halls4->Location = System::Drawing::Point(469, 166);
            this->halls4->Margin = System::Windows::Forms::Padding(2);
            this->halls4->Name = L"halls4";
            this->halls4->Size = System::Drawing::Size(92, 21);
            this->halls4->TabIndex = 14;
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(45, 150);
            this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(39, 13);
            this->label9->TabIndex = 19;
            this->label9->Text = L"Halls 1";
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Location = System::Drawing::Point(195, 150);
            this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(39, 13);
            this->label10->TabIndex = 20;
            this->label10->Text = L"Halls 2";
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Location = System::Drawing::Point(345, 150);
            this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(39, 13);
            this->label11->TabIndex = 21;
            this->label11->Text = L"Halls 3";
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Location = System::Drawing::Point(495, 150);
            this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(39, 13);
            this->label12->TabIndex = 22;
            this->label12->Text = L"Halls 4";
            // 
            // caverns1
            // 
            this->caverns1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->caverns1->FormattingEnabled = true;
            this->caverns1->Location = System::Drawing::Point(19, 236);
            this->caverns1->Margin = System::Windows::Forms::Padding(2);
            this->caverns1->Name = L"caverns1";
            this->caverns1->Size = System::Drawing::Size(92, 21);
            this->caverns1->TabIndex = 16;
            // 
            // caverns2
            // 
            this->caverns2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->caverns2->FormattingEnabled = true;
            this->caverns2->Location = System::Drawing::Point(169, 236);
            this->caverns2->Margin = System::Windows::Forms::Padding(2);
            this->caverns2->Name = L"caverns2";
            this->caverns2->Size = System::Drawing::Size(92, 21);
            this->caverns2->TabIndex = 17;
            // 
            // caverns3
            // 
            this->caverns3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->caverns3->FormattingEnabled = true;
            this->caverns3->Location = System::Drawing::Point(319, 236);
            this->caverns3->Margin = System::Windows::Forms::Padding(2);
            this->caverns3->Name = L"caverns3";
            this->caverns3->Size = System::Drawing::Size(92, 21);
            this->caverns3->TabIndex = 18;
            // 
            // caverns4
            // 
            this->caverns4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->caverns4->FormattingEnabled = true;
            this->caverns4->Location = System::Drawing::Point(469, 236);
            this->caverns4->Margin = System::Windows::Forms::Padding(2);
            this->caverns4->Name = L"caverns4";
            this->caverns4->Size = System::Drawing::Size(92, 21);
            this->caverns4->TabIndex = 19;
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->Location = System::Drawing::Point(37, 220);
            this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(55, 13);
            this->label13->TabIndex = 26;
            this->label13->Text = L"Caverns 1";
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->Location = System::Drawing::Point(187, 220);
            this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(55, 13);
            this->label14->TabIndex = 27;
            this->label14->Text = L"Caverns 2";
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->Location = System::Drawing::Point(337, 220);
            this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(55, 13);
            this->label15->TabIndex = 28;
            this->label15->Text = L"Caverns 3";
            // 
            // label16
            // 
            this->label16->AutoSize = true;
            this->label16->Location = System::Drawing::Point(487, 220);
            this->label16->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(55, 13);
            this->label16->TabIndex = 29;
            this->label16->Text = L"Caverns 4";
            // 
            // core1
            // 
            this->core1->AllowDrop = true;
            this->core1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->core1->FormattingEnabled = true;
            this->core1->Location = System::Drawing::Point(19, 295);
            this->core1->Margin = System::Windows::Forms::Padding(2);
            this->core1->Name = L"core1";
            this->core1->Size = System::Drawing::Size(92, 21);
            this->core1->TabIndex = 21;
            // 
            // core2
            // 
            this->core2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->core2->FormattingEnabled = true;
            this->core2->Location = System::Drawing::Point(169, 295);
            this->core2->Margin = System::Windows::Forms::Padding(2);
            this->core2->Name = L"core2";
            this->core2->Size = System::Drawing::Size(92, 21);
            this->core2->TabIndex = 22;
            // 
            // label17
            // 
            this->label17->AutoSize = true;
            this->label17->Location = System::Drawing::Point(46, 280);
            this->label17->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(38, 13);
            this->label17->TabIndex = 30;
            this->label17->Text = L"Core 1";
            // 
            // label18
            // 
            this->label18->AutoSize = true;
            this->label18->Location = System::Drawing::Point(196, 280);
            this->label18->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(38, 13);
            this->label18->TabIndex = 31;
            this->label18->Text = L"Core 2";
            // 
            // core3
            // 
            this->core3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->core3->FormattingEnabled = true;
            this->core3->Location = System::Drawing::Point(319, 295);
            this->core3->Margin = System::Windows::Forms::Padding(2);
            this->core3->Name = L"core3";
            this->core3->Size = System::Drawing::Size(92, 21);
            this->core3->TabIndex = 23;
            // 
            // core4
            // 
            this->core4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->core4->FormattingEnabled = true;
            this->core4->Location = System::Drawing::Point(469, 295);
            this->core4->Margin = System::Windows::Forms::Padding(2);
            this->core4->Name = L"core4";
            this->core4->Size = System::Drawing::Size(92, 21);
            this->core4->TabIndex = 24;
            // 
            // label19
            // 
            this->label19->AutoSize = true;
            this->label19->Location = System::Drawing::Point(346, 280);
            this->label19->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label19->Name = L"label19";
            this->label19->Size = System::Drawing::Size(38, 13);
            this->label19->TabIndex = 32;
            this->label19->Text = L"Core 3";
            // 
            // label20
            // 
            this->label20->AutoSize = true;
            this->label20->Location = System::Drawing::Point(496, 280);
            this->label20->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(38, 13);
            this->label20->TabIndex = 33;
            this->label20->Text = L"Core 4";
            // 
            // label21
            // 
            this->label21->AutoSize = true;
            this->label21->Location = System::Drawing::Point(17, 342);
            this->label21->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label21->Name = L"label21";
            this->label21->Size = System::Drawing::Size(165, 13);
            this->label21->TabIndex = 34;
            this->label21->Text = L"Amount of seeds you\'d like to find";
            // 
            // label22
            // 
            this->label22->AutoSize = true;
            this->label22->Location = System::Drawing::Point(19, 378);
            this->label22->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label22->Name = L"label22";
            this->label22->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->label22->Size = System::Drawing::Size(172, 13);
            this->label22->TabIndex = 35;
            this->label22->Text = L"Amount of seeds to search through";
            // 
            // amount_of_seeds_to_loop
            // 
            this->amount_of_seeds_to_loop->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
            this->amount_of_seeds_to_loop->Location = System::Drawing::Point(48, 393);
            this->amount_of_seeds_to_loop->Margin = System::Windows::Forms::Padding(2);
            this->amount_of_seeds_to_loop->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000000, 0, 0, 0 });
            this->amount_of_seeds_to_loop->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->amount_of_seeds_to_loop->Name = L"amount_of_seeds_to_loop";
            this->amount_of_seeds_to_loop->Size = System::Drawing::Size(90, 20);
            this->amount_of_seeds_to_loop->TabIndex = 36;
            this->amount_of_seeds_to_loop->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000000, 0, 0, 0 });
            // 
            // outputbox
            // 
            this->outputbox->BackColor = System::Drawing::SystemColors::WindowText;
            this->outputbox->ForeColor = System::Drawing::SystemColors::ControlLight;
            this->outputbox->Location = System::Drawing::Point(583, 16);
            this->outputbox->Margin = System::Windows::Forms::Padding(2);
            this->outputbox->Name = L"outputbox";
            this->outputbox->ReadOnly = true;
            this->outputbox->Size = System::Drawing::Size(127, 261);
            this->outputbox->TabIndex = 37;
            this->outputbox->Text = L"";
            // 
            // label23
            // 
            this->label23->AutoSize = true;
            this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label23->Location = System::Drawing::Point(613, 289);
            this->label23->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label23->Name = L"label23";
            this->label23->Size = System::Drawing::Size(81, 24);
            this->label23->TabIndex = 38;
            this->label23->Text = L"Shoguul";
            // 
            // shoguul
            // 
            this->shoguul->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->shoguul->FormattingEnabled = true;
            this->shoguul->Location = System::Drawing::Point(605, 315);
            this->shoguul->Margin = System::Windows::Forms::Padding(2);
            this->shoguul->Name = L"shoguul";
            this->shoguul->Size = System::Drawing::Size(92, 21);
            this->shoguul->TabIndex = 39;
            // 
            // shoguul_item1
            // 
            this->shoguul_item1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->shoguul_item1->FormattingEnabled = true;
            this->shoguul_item1->Location = System::Drawing::Point(606, 370);
            this->shoguul_item1->Margin = System::Windows::Forms::Padding(2);
            this->shoguul_item1->Name = L"shoguul_item1";
            this->shoguul_item1->Size = System::Drawing::Size(92, 21);
            this->shoguul_item1->TabIndex = 40;
            // 
            // label24
            // 
            this->label24->AutoSize = true;
            this->label24->Location = System::Drawing::Point(637, 354);
            this->label24->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label24->Name = L"label24";
            this->label24->Size = System::Drawing::Size(30, 13);
            this->label24->TabIndex = 42;
            this->label24->Text = L"Item:";
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(652, 403);
            this->button1->Margin = System::Windows::Forms::Padding(2);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(56, 19);
            this->button1->TabIndex = 43;
            this->button1->Text = L"Reset";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &NewsaveWindow::button1_Click);
            // 
            // tabControl1
            // 
            this->tabControl1->Controls->Add(this->tabPage1);
            this->tabControl1->Controls->Add(this->tabPage2);
            this->tabControl1->Location = System::Drawing::Point(0, 0);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(1485, 949);
            this->tabControl1->TabIndex = 44;
            // 
            // tabPage1
            // 
            this->tabPage1->Controls->Add(this->label1);
            this->tabPage1->Controls->Add(this->button1);
            this->tabPage1->Controls->Add(this->mine1);
            this->tabPage1->Controls->Add(this->label24);
            this->tabPage1->Controls->Add(this->find_seeds_btn);
            this->tabPage1->Controls->Add(this->shoguul_item1);
            this->tabPage1->Controls->Add(this->mine2);
            this->tabPage1->Controls->Add(this->shoguul);
            this->tabPage1->Controls->Add(this->mine3);
            this->tabPage1->Controls->Add(this->label23);
            this->tabPage1->Controls->Add(this->amount_of_seeds_to_find);
            this->tabPage1->Controls->Add(this->outputbox);
            this->tabPage1->Controls->Add(this->mine4);
            this->tabPage1->Controls->Add(this->amount_of_seeds_to_loop);
            this->tabPage1->Controls->Add(this->label2);
            this->tabPage1->Controls->Add(this->label22);
            this->tabPage1->Controls->Add(this->label3);
            this->tabPage1->Controls->Add(this->label21);
            this->tabPage1->Controls->Add(this->label4);
            this->tabPage1->Controls->Add(this->label20);
            this->tabPage1->Controls->Add(this->dungeon1);
            this->tabPage1->Controls->Add(this->label19);
            this->tabPage1->Controls->Add(this->label5);
            this->tabPage1->Controls->Add(this->core4);
            this->tabPage1->Controls->Add(this->Dungeon2);
            this->tabPage1->Controls->Add(this->core3);
            this->tabPage1->Controls->Add(this->label6);
            this->tabPage1->Controls->Add(this->label18);
            this->tabPage1->Controls->Add(this->Dungeon3);
            this->tabPage1->Controls->Add(this->label17);
            this->tabPage1->Controls->Add(this->label7);
            this->tabPage1->Controls->Add(this->core2);
            this->tabPage1->Controls->Add(this->Dungeon4);
            this->tabPage1->Controls->Add(this->core1);
            this->tabPage1->Controls->Add(this->label8);
            this->tabPage1->Controls->Add(this->label16);
            this->tabPage1->Controls->Add(this->halls1);
            this->tabPage1->Controls->Add(this->label15);
            this->tabPage1->Controls->Add(this->halls2);
            this->tabPage1->Controls->Add(this->label14);
            this->tabPage1->Controls->Add(this->halls3);
            this->tabPage1->Controls->Add(this->label13);
            this->tabPage1->Controls->Add(this->halls4);
            this->tabPage1->Controls->Add(this->caverns4);
            this->tabPage1->Controls->Add(this->label9);
            this->tabPage1->Controls->Add(this->caverns3);
            this->tabPage1->Controls->Add(this->label10);
            this->tabPage1->Controls->Add(this->caverns2);
            this->tabPage1->Controls->Add(this->label11);
            this->tabPage1->Controls->Add(this->caverns1);
            this->tabPage1->Controls->Add(this->label12);
            this->tabPage1->Location = System::Drawing::Point(4, 22);
            this->tabPage1->Name = L"tabPage1";
            this->tabPage1->Padding = System::Windows::Forms::Padding(3);
            this->tabPage1->Size = System::Drawing::Size(726, 430);
            this->tabPage1->TabIndex = 0;
            this->tabPage1->Text = L"Seed Search";
            this->tabPage1->UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this->tabPage2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(109)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
                static_cast<System::Int32>(static_cast<System::Byte>(67)));
            this->tabPage2->Controls->Add(this->pictureBox11);
            this->tabPage2->Controls->Add(this->pictureBox12);
            this->tabPage2->Controls->Add(this->pictureBox13);
            this->tabPage2->Controls->Add(this->pictureBox14);
            this->tabPage2->Controls->Add(this->pictureBox15);
            this->tabPage2->Controls->Add(this->pictureBox16);
            this->tabPage2->Controls->Add(this->pictureBox17);
            this->tabPage2->Controls->Add(this->pictureBox18);
            this->tabPage2->Controls->Add(this->pictureBox19);
            this->tabPage2->Controls->Add(this->pictureBox20);
            this->tabPage2->Controls->Add(this->pictureBox6);
            this->tabPage2->Controls->Add(this->pictureBox7);
            this->tabPage2->Controls->Add(this->pictureBox8);
            this->tabPage2->Controls->Add(this->pictureBox9);
            this->tabPage2->Controls->Add(this->pictureBox10);
            this->tabPage2->Controls->Add(this->pictureBox5);
            this->tabPage2->Controls->Add(this->pictureBox4);
            this->tabPage2->Controls->Add(this->pictureBox3);
            this->tabPage2->Controls->Add(this->pictureBox2);
            this->tabPage2->Controls->Add(this->pictureBox1);
            this->tabPage2->Location = System::Drawing::Point(4, 22);
            this->tabPage2->Name = L"tabPage2";
            this->tabPage2->Padding = System::Windows::Forms::Padding(3);
            this->tabPage2->Size = System::Drawing::Size(1477, 923);
            this->tabPage2->TabIndex = 1;
            this->tabPage2->Text = L"Layout Viewer";
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(8, 6);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(216, 216);
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            // 
            // pictureBox2
            // 
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(230, 6);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(216, 216);
            this->pictureBox2->TabIndex = 1;
            this->pictureBox2->TabStop = false;
            // 
            // pictureBox3
            // 
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(452, 6);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(216, 216);
            this->pictureBox3->TabIndex = 2;
            this->pictureBox3->TabStop = false;
            // 
            // pictureBox4
            // 
            this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
            this->pictureBox4->Location = System::Drawing::Point(674, 6);
            this->pictureBox4->Name = L"pictureBox4";
            this->pictureBox4->Size = System::Drawing::Size(216, 216);
            this->pictureBox4->TabIndex = 3;
            this->pictureBox4->TabStop = false;
            // 
            // pictureBox5
            // 
            this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
            this->pictureBox5->Location = System::Drawing::Point(896, 6);
            this->pictureBox5->Name = L"pictureBox5";
            this->pictureBox5->Size = System::Drawing::Size(216, 216);
            this->pictureBox5->TabIndex = 4;
            this->pictureBox5->TabStop = false;
            // 
            // pictureBox6
            // 
            this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
            this->pictureBox6->Location = System::Drawing::Point(896, 228);
            this->pictureBox6->Name = L"pictureBox6";
            this->pictureBox6->Size = System::Drawing::Size(216, 216);
            this->pictureBox6->TabIndex = 9;
            this->pictureBox6->TabStop = false;
            // 
            // pictureBox7
            // 
            this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
            this->pictureBox7->Location = System::Drawing::Point(674, 228);
            this->pictureBox7->Name = L"pictureBox7";
            this->pictureBox7->Size = System::Drawing::Size(216, 216);
            this->pictureBox7->TabIndex = 8;
            this->pictureBox7->TabStop = false;
            // 
            // pictureBox8
            // 
            this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
            this->pictureBox8->Location = System::Drawing::Point(452, 228);
            this->pictureBox8->Name = L"pictureBox8";
            this->pictureBox8->Size = System::Drawing::Size(216, 216);
            this->pictureBox8->TabIndex = 7;
            this->pictureBox8->TabStop = false;
            // 
            // pictureBox9
            // 
            this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
            this->pictureBox9->Location = System::Drawing::Point(230, 228);
            this->pictureBox9->Name = L"pictureBox9";
            this->pictureBox9->Size = System::Drawing::Size(216, 216);
            this->pictureBox9->TabIndex = 6;
            this->pictureBox9->TabStop = false;
            // 
            // pictureBox10
            // 
            this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
            this->pictureBox10->Location = System::Drawing::Point(8, 228);
            this->pictureBox10->Name = L"pictureBox10";
            this->pictureBox10->Size = System::Drawing::Size(216, 216);
            this->pictureBox10->TabIndex = 5;
            this->pictureBox10->TabStop = false;
            // 
            // pictureBox11
            // 
            this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.Image")));
            this->pictureBox11->Location = System::Drawing::Point(896, 672);
            this->pictureBox11->Name = L"pictureBox11";
            this->pictureBox11->Size = System::Drawing::Size(216, 216);
            this->pictureBox11->TabIndex = 19;
            this->pictureBox11->TabStop = false;
            // 
            // pictureBox12
            // 
            this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.Image")));
            this->pictureBox12->Location = System::Drawing::Point(674, 672);
            this->pictureBox12->Name = L"pictureBox12";
            this->pictureBox12->Size = System::Drawing::Size(216, 216);
            this->pictureBox12->TabIndex = 18;
            this->pictureBox12->TabStop = false;
            // 
            // pictureBox13
            // 
            this->pictureBox13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox13.Image")));
            this->pictureBox13->Location = System::Drawing::Point(452, 672);
            this->pictureBox13->Name = L"pictureBox13";
            this->pictureBox13->Size = System::Drawing::Size(216, 216);
            this->pictureBox13->TabIndex = 17;
            this->pictureBox13->TabStop = false;
            // 
            // pictureBox14
            // 
            this->pictureBox14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox14.Image")));
            this->pictureBox14->Location = System::Drawing::Point(230, 672);
            this->pictureBox14->Name = L"pictureBox14";
            this->pictureBox14->Size = System::Drawing::Size(216, 216);
            this->pictureBox14->TabIndex = 16;
            this->pictureBox14->TabStop = false;
            // 
            // pictureBox15
            // 
            this->pictureBox15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox15.Image")));
            this->pictureBox15->Location = System::Drawing::Point(8, 672);
            this->pictureBox15->Name = L"pictureBox15";
            this->pictureBox15->Size = System::Drawing::Size(216, 216);
            this->pictureBox15->TabIndex = 15;
            this->pictureBox15->TabStop = false;
            // 
            // pictureBox16
            // 
            this->pictureBox16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox16.Image")));
            this->pictureBox16->Location = System::Drawing::Point(896, 450);
            this->pictureBox16->Name = L"pictureBox16";
            this->pictureBox16->Size = System::Drawing::Size(216, 216);
            this->pictureBox16->TabIndex = 14;
            this->pictureBox16->TabStop = false;
            // 
            // pictureBox17
            // 
            this->pictureBox17->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox17.Image")));
            this->pictureBox17->Location = System::Drawing::Point(674, 450);
            this->pictureBox17->Name = L"pictureBox17";
            this->pictureBox17->Size = System::Drawing::Size(216, 216);
            this->pictureBox17->TabIndex = 13;
            this->pictureBox17->TabStop = false;
            // 
            // pictureBox18
            // 
            this->pictureBox18->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox18.Image")));
            this->pictureBox18->Location = System::Drawing::Point(452, 450);
            this->pictureBox18->Name = L"pictureBox18";
            this->pictureBox18->Size = System::Drawing::Size(216, 216);
            this->pictureBox18->TabIndex = 12;
            this->pictureBox18->TabStop = false;
            // 
            // pictureBox19
            // 
            this->pictureBox19->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox19.Image")));
            this->pictureBox19->Location = System::Drawing::Point(230, 450);
            this->pictureBox19->Name = L"pictureBox19";
            this->pictureBox19->Size = System::Drawing::Size(216, 216);
            this->pictureBox19->TabIndex = 11;
            this->pictureBox19->TabStop = false;
            // 
            // pictureBox20
            // 
            this->pictureBox20->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox20.Image")));
            this->pictureBox20->Location = System::Drawing::Point(8, 450);
            this->pictureBox20->Name = L"pictureBox20";
            this->pictureBox20->Size = System::Drawing::Size(216, 216);
            this->pictureBox20->TabIndex = 10;
            this->pictureBox20->TabStop = false;
            // 
            // NewsaveWindow
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(109)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
                static_cast<System::Int32>(static_cast<System::Byte>(67)));
            this->ClientSize = System::Drawing::Size(1484, 946);
            this->Controls->Add(this->tabControl1);
            this->Margin = System::Windows::Forms::Padding(2);
            this->Name = L"NewsaveWindow";
            this->Text = L"Newsave Seed Gen (cool version)";
            this->Load += gcnew System::EventHandler(this, &NewsaveWindow::NewsaveWindow_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount_of_seeds_to_find))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount_of_seeds_to_loop))->EndInit();
            this->tabControl1->ResumeLayout(false);
            this->tabPage1->ResumeLayout(false);
            this->tabPage1->PerformLayout();
            this->tabPage2->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
    private:
        std::string to_std_string(String^ input)
        {
            const auto chars = static_cast<char*>(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(input).
                ToPointer());
            std::string output(chars);
            Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr(chars));
            return output;
        }

        System::Void find_seeds_btn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            Output output = get_output_from_user();

            //this calculates the seeds and puts it into output
            Newsave(output, static_cast<int_fast16_t>(amount_of_seeds_to_find->Value)).calculate_seeds(
                static_cast<uint_fast32_t>(amount_of_seeds_to_loop->Value));


            //show user new output data
            outputbox->Text = gcnew String(output.output_to_string().c_str());
        }

    private:
        /**
         * \brief gets all user input from combo boxes and input fields and puts it in an object
         * \return Output object with all floors (map)
         */
        Output get_output_from_user()
        {
            std::vector<Floor> floors = {}; //init floors

            //foreach loop over every "controls" (aka elements on screen)
            for each (Control^ control in this->Controls)
            {
                if (control->GetType() == ComboBox::typeid)
                {
                    auto box = static_cast<ComboBox^>(control);
                    const auto item_index = static_cast<int_fast16_t>(box->SelectedValue); //selected item

                    //filter special combo boxes
                    if (item_index == NOTHING || box == mine1 || box == shoguul || box == shoguul_item1)
                        continue;

                    //add floors
                    floors.push_back(Floor(box->TabIndex, item_index));
                }
            }

            //put everything together in a map, see more at map
            const Map map = Map(static_cast<int>(mine1->SelectedValue), floors,
                                Shoguul(static_cast<int_fast16_t>(shoguul->SelectedValue),
                                        static_cast<int_fast16_t>(shoguul_item1->SelectedValue)));

            return Output(map, static_cast<uint16_t>(amount_of_seeds_to_find->Value));
        }

    private:
        System::Void NewsaveWindow_Load(System::Object^ sender, System::EventArgs^ e)
        {
            init_dropdowns();
        }

    private:
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
        {
            for each (Control^ control in this->Controls)
            {
                if (control->GetType() == ComboBox::typeid)
                {
                    auto box = static_cast<ComboBox^>(control);
                    box->SelectedIndex = 0;
                }
            }
            outputbox->Text = "";
        }
};
}
